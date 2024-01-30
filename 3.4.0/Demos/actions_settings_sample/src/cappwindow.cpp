// cappwindow.cpp implementation file
/*
* Copyright notice:
* Copyright (c) 2010-2016 3Dconnexion. All rights reserved.
*
* This file and source code are an integral part of the "3Dconnexion
* Software Developer Kit", including all accompanying documentation,
* and is protected by intellectual property laws. All use of the
* 3Dconnexion Software Developer Kit is subject to the License
* Agreement found in the "LicenseAgreementSDK.txt" file.
* All rights not expressly granted by 3Dconnexion are reserved.
*/
#include "stdafx.h"
///////////////////////////////////////////////////////////////////////////////////
// History
//
// $Id: cappwindow.cpp 14689 2018-01-23 08:46:38Z mbonk $
//
// 02/04/13 MSB Initial Design
//
#pragma warning(disable : 4995)
#pragma warning(disable : 4996)

#include "cappwindow.hpp"
#include "resource.h"
#include "caboutdialog.hpp"

// atl
#include <atltypes.h>
#include <atlimage.h>

// stl
#include <iostream>
#include <algorithm>
#include <memory>
#if (_MSCVER>=1600)
#include <cstdint>
#else
#include "cstdint.hpp"
using tdx::uint16_t;
#endif

// 3dxware
#pragma comment(lib , "siapp.lib")

#define WRITE_ALL_ACTIONS_ON_INITIALIZATION 1
/////////////////////////////////////////////////////////////////////////////
// CAppWindow

// Construction
CAppWindow::CAppWindow()
  : m_siHdl(INVALID_SI_HANDLE)
{
}

BOOL CAppWindow::Create()
{
  BOOL bResult = FALSE;
  if (!IsWindow())
  {
    // Clean up
    if (m_hWnd)
      Close();

    WTL::CMenuHandle menu;
    menu.LoadMenu(IDC_TEST_ACTION_INTERFACE);

    if (_MyBase::Create(NULL
      , 0
      , L"Action Interface"
      , 0
      , 0
      , static_cast<HMENU>(menu)) != NULL)
    {
      HANDLE hIcon = ::LoadImage(_AtlBaseModule.GetResourceInstance()
        , MAKEINTRESOURCE(IDI_TEST_ACTION_INTERFACE)
        , IMAGE_ICON
        , 0
        , 0
        , LR_SHARED | LR_DEFAULTSIZE);
      ::DestroyIcon(this->SetIcon(static_cast<HICON>(hIcon)));

      ::SiInitialize();

      SiOpenData siOpenData;
      char windowName[MAX_PATH];

      ::SiOpenWinInit(&siOpenData, m_hWnd);

      GetWindowTextA(m_hWnd, windowName, MAX_PATH);

      m_siHdl = ::SiOpen(windowName, SI_ANY_DEVICE, SI_NO_MASK, SI_EVENT, &siOpenData);

      std::cout << "SiOpen return SiHhl = " << std::hex << m_siHdl << std::dec << std::endl;

      if (m_siHdl != INVALID_SI_HANDLE)
      {
        // Export all action images. If we need to, we can export more images later.
        uint32_t error = write_images(m_siHdl);

#if WRITE_ALL_ACTIONS_ON_INITIALIZATION
        // If we know the full extend of the action sets we could export them now
        if (error == SPW_NO_ERROR)
        {
          error = write_multiple_actionsets(m_siHdl);
          std::cout << "write_multiple_actionsets returned error = " << std::hex << error << std::dec << std::endl;
        }
#else
        // In this sample we assume that the action sets except for the startup action set
        // cannot be determined at startup
        if (error == SPW_NO_ERROR)
        {
          error = write_actions_startup(m_siHdl);
          std::cout << "write_actions_startup returned error = " << std::hex << error << std::dec << std::endl;
        }
#endif
        // Activate the initial startup action set
        if (error == SPW_NO_ERROR)
          error = activate_actionset_startup(m_siHdl);

        if (error == SPW_NO_ERROR)
          bResult = TRUE;
      }
    }
  }
  return bResult;
}

BOOL CAppWindow::Close()
{
  BOOL bResult = FALSE;
  if (m_siHdl != INVALID_SI_HANDLE)
  {
    SpwRetVal error;

    error = ::SiClose(m_siHdl);

    std::cout << "SiClose(" << std::hex << m_siHdl << ") return =" << std::dec << error << std::endl;

    m_siHdl = INVALID_SI_HANDLE;
  }

  if (IsWindow())
  {
    bResult = DestroyWindow();
  }
  else if (m_hWnd)
  {
    CloseHandle(Detach());
  }
  return bResult;
}

CAppWindow::~CAppWindow()
{
  Close();
}

// Message handlers
LRESULT CAppWindow::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
#ifdef AFX_MANAGE_STATE
  AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif
  LRESULT lResult = TRUE;
  bHandled = FALSE;

  _RPT0(_CRT_WARN, "CAppWindow::OnClose\n");

  return lResult;
}

LRESULT CAppWindow::OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
#ifdef AFX_MANAGE_STATE
  AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif
  LRESULT lResult = TRUE;
  bHandled = FALSE;

  _RPT0(_CRT_WARN, "CAppWindow::OnDestroy\n");

  ::PostQuitMessage(0);

  return lResult;
}

LRESULT CAppWindow::OnQuit(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
#ifdef AFX_MANAGE_STATE
  AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif
  LRESULT lResult = TRUE;
  bHandled = FALSE;

  _RPT0(_CRT_WARN, "CAppWindow::OnQuit\n");

  return lResult;
}

LRESULT CAppWindow::OnSpacewareMessage00(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
#ifdef AFX_MANAGE_STATE
  AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif
  LRESULT lResult = TRUE;
  bHandled = FALSE;

  uint32_t error = SPW_NO_ERROR;
  SiGetEventData eData;
  SiSpwEvent spwEvent;

  SiGetEventWinInit(&eData, uMsg, wParam, lParam);
  if (SiGetEvent(m_siHdl, SI_AVERAGE_EVENTS, &eData, &spwEvent) == SI_IS_EVENT)
  {
    switch (spwEvent.type)
    {
    case SI_ZERO_EVENT:
    case SI_MOTION_EVENT:
      break;
    case SI_APP_EVENT:
    {
      // handle the application actions
      size_t len = strnlen_s(spwEvent.u.appCommandData.id.appCmdID, SI_MAXAPPCMDID);
      if (len == 0 || len == SI_MAXAPPCMDID)
        return SI_BAD_VALUE;

      std::cout << "Execute application action " << spwEvent.u.appCommandData.id.appCmdID << (spwEvent.u.appCommandData.pressed ? " button press" : " button release") << std::endl;
      if (!spwEvent.u.appCommandData.pressed)
        MessageBoxA(NULL
          , spwEvent.u.appCommandData.id.appCmdID
          , "Action"
          , MB_OK);
    }
    break;
    case SI_CMD_EVENT:
      // handle the s80 commands
      break;
    }
  }
  return lResult;
}

LRESULT CAppWindow::OnNcDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
#ifdef AFX_MANAGE_STATE
  AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif
  LRESULT lResult = TRUE;
  bHandled = FALSE;

  _RPT0(_CRT_WARN, "CAppWindow::OnNcDestroy\n");

  return lResult;
}

//////////////////////////////////////////////////////////////////////////////////////////////
// Command handlers
LRESULT CAppWindow::OnAbout(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
#ifdef AFX_MANAGE_STATE
  AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif

  LRESULT lResult = TRUE;
  bHandled = FALSE;

  CAboutDialog about;

  about.DoModal();

  return lResult;
}

LRESULT CAppWindow::OnActivateActionSet(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
#ifdef AFX_MANAGE_STATE
  AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif

  LRESULT lResult = TRUE;
  bHandled = FALSE;

  switch (wID)
  {
  case ID_ACTIVATE_MAINMODE:
  {
    // If the commands within an actions set do no change then writing them only
    // needs to be done once and should be done when initializing the Si interface
    // see write_multiple_actionsets in CAppWindow::Create()
#if WRITE_ALL_ACTIONS_ON_INITIALIZATION==0
    uint32_t error = write_actions_main(m_siHdl);
    std::cout << "write_actions_main returned error = " << std::hex << error << std::dec << std::endl;
#endif

    lResult = activate_actionset_main(m_siHdl);
  }
  break;

  case ID_ACTIVATE_SPECIALCHARSMODE:
  {
    // If the commands within an actions set do no change then writing them only
    // needs to be done once and should be done when initializing the Si interface
    // see write_multiple_actionsets in CAppWindow::Create()
#if WRITE_ALL_ACTIONS_ON_INITIALIZATION==0
    uint32_t error = write_actions_specialchars(m_siHdl);
    std::cout << "write_actions_specialchars returned error = " << std::hex << error << std::dec << std::endl;
#endif

    lResult = activate_actionset_specialchars(m_siHdl);
  }
  break;

  case ID_ACTIVATE_STARTUPMODE:
  {
    lResult = activate_actionset_startup(m_siHdl);
  }
  break;
  }

  return lResult;
}