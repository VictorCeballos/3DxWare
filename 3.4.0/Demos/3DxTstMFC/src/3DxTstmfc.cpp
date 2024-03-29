// 3Dxtestmfc.cpp : Defines the class behaviors for the application.
//
/*
* Copyright notice:
* Copyright (c) 1998-2015 3Dconnexion. All rights reserved.
*
* This file and source code are an integral part of the "3Dconnexion
* Software Developer Kit", including all accompanying documentation,
* and is protected by intellectual property laws. All use of the
* 3Dconnexion Software Developer Kit is subject to the License
* Agreement found in the "LicenseAgreementSDK.txt" file.
* All rights not expressly granted by 3Dconnexion are reserved.
*/
#include "stdafx.h"
#include "3Dxtstmfc.h"

#include "MainFrm.h"
#include "3DxDoc.h"
#include "3DxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSbtestmfcApp

BEGIN_MESSAGE_MAP(CSbtestmfcApp, CWinApp)
  //{{AFX_MSG_MAP(CSbtestmfcApp)
  ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
  // NOTE - the ClassWizard will add and remove mapping macros here.
  //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
  // Standard file based document commands
  ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
  ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSbtestmfcApp construction

CSbtestmfcApp::CSbtestmfcApp()
{
  // TODO: add construction code here,
  // Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CSbtestmfcApp object

CSbtestmfcApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CSbtestmfcApp initialization

BOOL CSbtestmfcApp::InitInstance()
{
  // Standard initialization
  // If you are not using these features and wish to reduce the size
  //  of your final executable, you should remove from the following
  //  the specific initialization routines you do not need.

  // Change the registry key under which our settings are stored.
  // You should modify this string to be something appropriate
  // such as the name of your company or organization.
  SetRegistryKey(_T("Local AppWizard-Generated Applications"));

  LoadStdProfileSettings(0);  // Load standard INI file options (including MRU)

  // Register the application's document templates.  Document templates
  //  serve as the connection between documents, frame windows and views.

  CSingleDocTemplate* pDocTemplate;
  pDocTemplate = new CSingleDocTemplate(
    IDR_MAINFRAME,
    RUNTIME_CLASS(CSbtestmfcDoc),
    RUNTIME_CLASS(CMainFrame),       // main SDI frame window
    RUNTIME_CLASS(CSbtestmfcView));
  AddDocTemplate(pDocTemplate);

  // Parse command line for standard shell commands, DDE, file open
  CCommandLineInfo cmdInfo;
  ParseCommandLine(cmdInfo);

  // Dispatch commands specified on the command line
  if (!ProcessShellCommand(cmdInfo))
    return FALSE;

  // The one and only window has been initialized, so show and update it.
  m_pMainWnd->ShowWindow(SW_SHOW);
  m_pMainWnd->UpdateWindow();

  return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
  CAboutDlg();

  // Dialog Data
  //{{AFX_DATA(CAboutDlg)
  enum { IDD = IDD_ABOUTBOX };
  //}}AFX_DATA

  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CAboutDlg)
protected:
  virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
  //}}AFX_VIRTUAL

  // Implementation
protected:
  //{{AFX_MSG(CAboutDlg)
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
  //{{AFX_DATA_INIT(CAboutDlg)
  //}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  //{{AFX_DATA_MAP(CAboutDlg)
  //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
  //{{AFX_MSG_MAP(CAboutDlg)
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CSbtestmfcApp::OnAppAbout()
{
  CAboutDlg aboutDlg;
  aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CSbtestmfcApp commands