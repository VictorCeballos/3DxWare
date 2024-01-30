// caboutdialog.cpp : implementation file
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
// $Id: caboutdialog.cpp 13201 2016-07-21 10:17:18Z mbonk $
//
// 02/04/13 MSB Initial Design
//
#include "stdafx.h"
#include "caboutdialog.hpp"
#include "version.h"

#pragma warning (push)
#pragma warning (disable : 4995)

CAboutDialog::CAboutDialog()
{
}

CAboutDialog::~CAboutDialog()
{
}

LRESULT CAboutDialog::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
#ifdef AFX_MANAGE_STATE
  AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif

  bHandled = FALSE;
  EndDialog(0);
  return 0;
}

LRESULT CAboutDialog::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
#ifdef AFX_MANAGE_STATE
  AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif
  ATL::CString strVersion(_T(FILE_DESCRIPTION_STR));
  strVersion += _T("\nVersion");
  strVersion += _T(PRODUCT_VERSION_STR);
  strVersion += _T("\n");
  strVersion += _T(LEGAL_COPYRIGHT_STR);

  SetDlgItemText(IDC_ABOUT_Version, strVersion.GetString());

  return TRUE;
}

LRESULT CAboutDialog::OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
#ifdef AFX_MANAGE_STATE
  AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif
  bHandled = FALSE;
  EndDialog(0);
  return 0;
}