#ifndef CTESTWINDOW_HPP_INCLUDED_
#define CTESTWINDOW_HPP_INCLUDED_
// cappwindow.hpp
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

///////////////////////////////////////////////////////////////////////////////////
// History
//
// $Id: cappwindow.hpp 14689 2018-01-23 08:46:38Z mbonk $
//
// 02/04/13 MSB Initial Design
//
#pragma once

#pragma warning (push)
#include <atlbase.h>
#include <atlwin.h>
#include <atlstr.h>

#include "action_interface.h"
#include "resource.h"

//stl
#include <vector>

// 3dxware
#include "si.h"
#include "siapp.h"
#define INVALID_SI_HANDLE  (reinterpret_cast<SiHdl>(-1LL))

// wtl
#pragma warning (disable : 4996)

#include "wtl/atlapp.h"
#include "wtl/atluser.h"

///////////////////////////////////////////////////////////////////////////////////
//
const UINT WM_SPACEWAREMESSAGE00 = ::RegisterWindowMessageW(L"SpaceWareMessage00");

///////////////////////////////////////////////////////////////////////////////////
// CAppWindow
class CAppWindow
  : public ATL::CWindowImpl<CAppWindow, ATL::CWindow, ATL::CFrameWinTraits>
  , public ATL::CRTThreadTraits
{
  typedef ATL::CWindowImpl<CAppWindow, ATL::CWindow, ATL::CFrameWinTraits> _MyBase;
  // Construction
public:
  CAppWindow();

  // Operations
public:
  BOOL Create();
  BOOL Close();

  // Destruction
public:
  virtual ~CAppWindow();

  // Attributes
private:
  SiHdl m_siHdl;

  // Implementation
private:
  BEGIN_MSG_MAP(CAppWindow)
    // Message handlers
    MESSAGE_HANDLER(WM_CLOSE, OnClose)
    MESSAGE_HANDLER(WM_NCDESTROY, OnNcDestroy)
    MESSAGE_HANDLER(WM_QUIT, OnQuit)
    MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
    MESSAGE_HANDLER(WM_SPACEWAREMESSAGE00, OnSpacewareMessage00)

    // Menu command handlers
    COMMAND_ID_HANDLER(IDM_ABOUT, OnAbout)

    COMMAND_ID_HANDLER(ID_ACTIVATE_MAINMODE, OnActivateActionSet)
    COMMAND_ID_HANDLER(ID_ACTIVATE_SPECIALCHARSMODE, OnActivateActionSet)
    COMMAND_ID_HANDLER(ID_ACTIVATE_STARTUPMODE, OnActivateActionSet)
  END_MSG_MAP()

private:
  // Message handlers
  LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
  LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
  LRESULT OnNcDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
  LRESULT OnQuit(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
  LRESULT OnSpacewareMessage00(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

  // Command handlers
  LRESULT OnAbout(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
  LRESULT OnExit(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

  LRESULT OnActivateActionSet(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

  LRESULT OnSiOpen(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
  LRESULT OnSiClose(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

private:
  std::vector<SiHdl> m_siHdls;
}; // CAppWindow

#pragma warning (pop)

#endif // CTESTWINDOW_HPP_INCLUDED_