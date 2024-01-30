/////////////////////////////////////////////////////////////////////////////
// cmodule.cpp : defines the initialization routines for the app
//
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
// $Id: cmodule.cpp 13201 2016-07-21 10:17:18Z mbonk $
//
// 01/24/13 MSB Initial Design
//

#include "cmodule.hpp"

//stl
#if __DEBUG
#include <io.h>
#include <fcntl.h>
#endif

// The module
CModule _theModule;

// CModule
CModule::CModule()
{
#if __DEBUG
  BOOL b = AllocConsole();
  *stdout = *_tfdopen(_open_osfhandle((intptr_t)GetStdHandle(STD_OUTPUT_HANDLE), _O_WRONLY), _T("a"));
#endif
}

CModule::~CModule()
{
}

HRESULT CModule::PreMessageLoop(int nShowCmd)
{
  HRESULT hr = _MyBase::PreMessageLoop(nShowCmd);

  if (!theWindow.Create())
    return HRESULT_FROM_WIN32(::GetLastError());

  theWindow.ShowWindow(nShowCmd);

  return hr;
}

///////////////////////////////////////////////////////////////////////////////////
// Module entry point
int APIENTRY _tWinMain(HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  LPTSTR    lpCmdLine,
  int       nCmdShow)
{
  UNREFERENCED_PARAMETER(hInstance);
  UNREFERENCED_PARAMETER(hPrevInstance);
  UNREFERENCED_PARAMETER(lpCmdLine);

  return _theModule.WinMain(nCmdShow);
}