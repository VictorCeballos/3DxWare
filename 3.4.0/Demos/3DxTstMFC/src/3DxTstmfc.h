// sbtestmfc.h : main header file for the SBTESTMFC application
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
 *
 */
#if !defined(AFX_SBTESTMFC_H__EC60F755_86A7_11D1_A7B6_0060979D0B2E__INCLUDED_)
#define AFX_SBTESTMFC_H__EC60F755_86A7_11D1_A7B6_0060979D0B2E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSbtestmfcApp:
// See sbtestmfc.cpp for the implementation of this class
//

class CSbtestmfcApp : public CWinApp
{
public:
	CSbtestmfcApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSbtestmfcApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSbtestmfcApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SBTESTMFC_H__EC60F755_86A7_11D1_A7B6_0060979D0B2E__INCLUDED_)
