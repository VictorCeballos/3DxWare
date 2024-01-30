// sbtestmfcDoc.cpp : implementation of the CSbtestmfcDoc class
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

#include "3DxDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSbtestmfcDoc

IMPLEMENT_DYNCREATE(CSbtestmfcDoc, CDocument)

BEGIN_MESSAGE_MAP(CSbtestmfcDoc, CDocument)
  //{{AFX_MSG_MAP(CSbtestmfcDoc)
  // NOTE - the ClassWizard will add and remove mapping macros here.
  //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSbtestmfcDoc construction/destruction

CSbtestmfcDoc::CSbtestmfcDoc()
{
  // TODO: add one-time construction code here
}

CSbtestmfcDoc::~CSbtestmfcDoc()
{
}

BOOL CSbtestmfcDoc::OnNewDocument()
{
  if (!CDocument::OnNewDocument())
    return FALSE;

  // TODO: add reinitialization code here
  // (SDI documents will reuse this document)
  SetTitle(_T("SpaceWare"));
  return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CSbtestmfcDoc serialization

void CSbtestmfcDoc::Serialize(CArchive& ar)
{
  if (ar.IsStoring())
  {
    // TODO: add storing code here
  }
  else
  {
    // TODO: add loading code here
  }
}

/////////////////////////////////////////////////////////////////////////////
// CSbtestmfcDoc diagnostics

#ifdef _DEBUG
void CSbtestmfcDoc::AssertValid() const
{
  CDocument::AssertValid();
}

void CSbtestmfcDoc::Dump(CDumpContext& dc) const
{
  CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSbtestmfcDoc commands
