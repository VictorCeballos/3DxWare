// sbtestmfcDoc.h : interface of the CSbtestmfcDoc class
//
/////////////////////////////////////////////////////////////////////////////
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
#if !defined(AFX_SBTESTMFCDOC_H__EC60F75B_86A7_11D1_A7B6_0060979D0B2E__INCLUDED_)
#define AFX_SBTESTMFCDOC_H__EC60F75B_86A7_11D1_A7B6_0060979D0B2E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CSbtestmfcDoc : public CDocument
{
protected: // create from serialization only
	CSbtestmfcDoc();
	DECLARE_DYNCREATE(CSbtestmfcDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSbtestmfcDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSbtestmfcDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSbtestmfcDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SBTESTMFCDOC_H__EC60F75B_86A7_11D1_A7B6_0060979D0B2E__INCLUDED_)
