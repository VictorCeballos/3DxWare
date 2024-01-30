/*----------------------------------------------------------------------
 *  3DxVIEW.H  -- Basic Program to init the 3D mouse, read its data and 
 *                  print it out.  The most important function is the 
 *                  Pre Translate Message function because we trap 
 *                  messages there.
 *
 *  Originally written By Elio Querze
 *  
 *
 *----------------------------------------------------------------------
 *
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
static char SbTestMfcViewCvsId[]="(C) 3Dconnexion: $Id: 3DxVIEW.H 11091 2015-01-09 11:02:45Z jwick $";

#if !defined(AFX_SBTESTMFCVIEW_H__EC60F75D_86A7_11D1_A7B6_0060979D0B2E__INCLUDED_)
#define AFX_SBTESTMFCVIEW_H__EC60F75D_86A7_11D1_A7B6_0060979D0B2E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "si.h"        /* Required for any 3DxWare driver support within an app.*/

class CSbtestmfcView : public CView
{
protected: // create from serialization only
	CSbtestmfcView();
	DECLARE_DYNCREATE(CSbtestmfcView)

// Attributes
public:
	CSbtestmfcDoc* GetDocument();
   
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSbtestmfcView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	//}}AFX_VIRTUAL

#if 0
	virtual BOOL PreTranslateMessage(MSG* pMsg);  //This where we trap the msgs
#endif
                                                      
// Implementation
public:
	virtual ~CSbtestmfcView();

   


#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

   /* 3D mouse Variables&Functions */
   
   /* Members */
   SiHdl       m_DevHdl;       /* Handle to 3D mouse Device */
   
   /* 3D Mouse Functions --See CPP File for Additional Details */
   int   SbInit();
   void  SbMotionEvent(SiSpwEvent *pEvent);
   void  SbZeroEvent();
   void  SbButtonPressEvent(int buttonnumber);
   void  SbButtonReleaseEvent(int buttonnumber);

   /* 3D Mouse helper function */
   unsigned long SbGetDevicePID(SiHdl& devHdl);

// Generated message map functions
protected:
	//{{AFX_MSG(CSbtestmfcView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg LRESULT On3DMouse( WPARAM wParam, LPARAM lParam );
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in sbtestmfcView.cpp
inline CSbtestmfcDoc* CSbtestmfcView::GetDocument()
   { return (CSbtestmfcDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SBTESTMFCVIEW_H__EC60F75D_86A7_11D1_A7B6_0060979D0B2E__INCLUDED_)
