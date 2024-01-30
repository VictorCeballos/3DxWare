#ifndef caboutdialog_HPP_INCLUDED_
#define caboutdialog_HPP_INCLUDED_
// caboutdialog.hpp : header file
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
#ifndef __cplusplus
#error caboutdialog requires C++ compilation (use a .cpp suffix)
#endif

///////////////////////////////////////////////////////////////////////////////////
// History
//
// $Id: caboutdialog.hpp 13201 2016-07-21 10:17:18Z mbonk $
//
// 02/04/13 MSB Initial Design
//

#pragma once

#include "resource.h"

// atl
#pragma warning (push)
#pragma warning (disable : 4995)

#include <atlwin.h>

////////////////////////////////////////////////////////////////////////////////////
// CAboutDialog
class CAboutDialog :
  public ATL::CDialogImpl<CAboutDialog>
{
  // Construction
public:
  CAboutDialog();
  virtual ~CAboutDialog();

private:
  BEGIN_MSG_MAP(CAboutDialog)
    MESSAGE_HANDLER(WM_CLOSE, OnClose)
    MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
    COMMAND_ID_HANDLER(IDOK, OnOK)
  END_MSG_MAP()

  // Message handlers
  LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
  LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

  // Command handlers
  LRESULT OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

public:
  enum { IDD = IDD_ABOUTBOX };
};

#endif // caboutdialog_HPP_INCLUDED_