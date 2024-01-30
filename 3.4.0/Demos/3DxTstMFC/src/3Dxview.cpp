/*----------------------------------------------------------------------
*  3Dxview.cpp  -- Basic MFC Program to initinalize a 3D mouse, read 
*                  its data and print it out.
*
*  Originally written By Elio Querze
*
*  NOTE: MUST LINK WITH SIAPP.LIB
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
static char CvsId[]="(C) 1998-2015 3Dconnexion: $Id: 3Dxview.cpp 11689 2015-08-10 12:23:51Z ngomes $";

#include "stdafx.h"
#include "3Dxtstmfc.h"
#include "3DxDoc.h"
#include "3DxView.h"

#include "virtualkeys.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/* 3DxWare SDK Specific Includes */
#include "si.h"        /* Required for any 3DxWare driver support within an app.*/
#include "spwmacro.h"  /* Common macros used by 3DxWare SDK functions. */
extern "C"
{
#include "siapp.h"     /* Required for siapp.lib symbols */
}

/////////////////////////////////////////////////////////////////////////////
// CSbtestmfcView

IMPLEMENT_DYNCREATE(CSbtestmfcView, CView)

int WM_3DMOUSE = RegisterWindowMessage (_T("SpaceWareMessage00"));
BEGIN_MESSAGE_MAP(CSbtestmfcView, CView)
  //{{AFX_MSG_MAP(CSbtestmfcView)
  ON_WM_CREATE()
  ON_REGISTERED_MESSAGE( WM_3DMOUSE, On3DMouse )
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSbtestmfcView construction/destruction

CSbtestmfcView::CSbtestmfcView() :
m_DevHdl(NULL)
{
}

CSbtestmfcView::~CSbtestmfcView()
{
}


/////////////////////////////////////////////////////////////////////////////
// CSbtestmfcView drawing

void CSbtestmfcView::OnDraw(CDC* pDC)
{
  /* When app loses and regains focus print this (also init) */   
  pDC->TextOut(  0 ,   0, _T("3D Mouse Ready"), 15);
  pDC->TextOut( 15 ,  60, _T("TX: 0"), 5);
  pDC->TextOut( 15 ,  80, _T("TY: 0"), 5);
  pDC->TextOut( 15 , 100, _T("TZ: 0"), 5);
  pDC->TextOut( 15 , 120, _T("RX: 0"), 5);
  pDC->TextOut( 15 , 140, _T("RY: 0"), 5);
  pDC->TextOut( 15 , 160, _T("RZ: 0"), 5);

}

/////////////////////////////////////////////////////////////////////////////
// CSbtestmfcView diagnostics

#ifdef _DEBUG
void CSbtestmfcView::AssertValid() const
{
  CView::AssertValid();
}

void CSbtestmfcView::Dump(CDumpContext& dc) const
{
  CView::Dump(dc);
}

CSbtestmfcDoc* CSbtestmfcView::GetDocument() // non-debug version is inline
{
  ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSbtestmfcDoc)));
  return (CSbtestmfcDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSbtestmfcView 3D Mouse Functions

/*--------------------------------------------------------------------------
* Function: CSbtestmfcView::SbInit()
*
* Description:
*    This function initializes the 3D mouse and opens ball for use.
*    
*
* Args: None
*    
*
* Return Value:
*    int  res         result of SiOpen, =0 if Fail =1 if it Works
*
*--------------------------------------------------------------------------*/
int
CSbtestmfcView::SbInit()
{
  int res;                                 //result of SiOpen, to be returned  
  SiOpenData oData;                        //OS Independent data to open ball  

  if (SiInitialize() == SPW_DLL_LOAD_ERROR)   //init the 3DxWare input library
  {
    MessageBox(_T("Error: Could not load SiAppDll dll files"),
      NULL, MB_ICONEXCLAMATION);
  }
  SiOpenWinInit (&oData, m_hWnd);          //init Win. platform specific data  

  //open data, which will check for device type and return the device handle
  // to be used by this function  
  if ( (m_DevHdl = SiOpen ("TestSP", SI_ANY_DEVICE, SI_NO_MASK,  
    SI_EVENT, &oData)) == NULL )
  {
    SiTerminate();  //called to shut down the 3DxWare input library 
    res = 0;        //could not open device
    return res; 
  }
  else
  {
    res = 1;        //opened device succesfully
    return res;  
  }  
}


/*----------------------------------------------------------------------
* Function: SbMotionEvent()
*
* Description:
*    This function receives motion information and prints out the info 
*    on screen.
*    
*
* Args:
*    SiSpwEvent *pEvent   Containts Data from a 3D Mouse Event
*
* Return Value:
*    NONE
*
*----------------------------------------------------------------------*/
void 
CSbtestmfcView::SbMotionEvent(SiSpwEvent *pEvent)
{  
  CDC* pDC;

  TCHAR buff0[20];                            /* text buffer for TX */
  TCHAR buff1[20];                            /* text buffer for TY */
  TCHAR buff2[20];                            /* text buffer for TZ */
  TCHAR buff3[20];                            /* text buffer for RX */
  TCHAR buff4[20];                            /* text buffer for RY */
  TCHAR buff5[20];                            /* text buffer for RZ */ 

  int len0,len1,len2,len3,len4,len5;        /* length of each buffer */

  /* put the actual ball data into the buffers */
  len0= _stprintf( buff0, _T("TX: %d         "), pEvent->u.spwData.mData[SI_TX] );
  len1= _stprintf( buff1, _T("TY: %d         "), pEvent->u.spwData.mData[SI_TY] );
  len2= _stprintf( buff2, _T("TZ: %d         "), pEvent->u.spwData.mData[SI_TZ] );
  len3= _stprintf( buff3, _T("RX: %d         "), pEvent->u.spwData.mData[SI_RX] );
  len4= _stprintf( buff4, _T("RY: %d         "), pEvent->u.spwData.mData[SI_RY] );
  len5= _stprintf( buff5, _T("RZ: %d         "), pEvent->u.spwData.mData[SI_RZ] );

  /* get handle of our window to draw on */
  pDC = GetDC();        

  /* print buffers */
  pDC->TextOut( 0 , 0, _T("Motion Event                "), 28);
  pDC->TextOut( 15 , 60, buff0, len0);
  pDC->TextOut( 15 , 80, buff1, len1);
  pDC->TextOut( 15 , 100, buff2, len2);
  pDC->TextOut( 15 , 120, buff3, len3);
  pDC->TextOut( 15 , 140, buff4, len4);
  pDC->TextOut( 15 , 160, buff5, len5);

  /*release our window handle */ 
  ReleaseDC(pDC);
}


/*----------------------------------------------------------------------
* Function: CSbtestmfcView::SbZeroEvent()
*
* Description:
*    This function clears the previous data, no motion data was received
*    
*    
*
* Args:
*    NONE
*
* Return Value:
*    NONE
*
*----------------------------------------------------------------------*/
void 
CSbtestmfcView::SbZeroEvent()
{
  /* get handle of our window to draw on */
  CDC* pDC;

  pDC = GetDC();  

  /* print null data */   
  pDC->TextOut(  0 ,   0, _T("Zero Event                  "), 28);
  pDC->TextOut( 15 ,  60, _T("TX: 0          "), 15);
  pDC->TextOut( 15 ,  80, _T("TY: 0          "), 15);
  pDC->TextOut( 15 , 100, _T("TZ: 0          "), 15);
  pDC->TextOut( 15 , 120, _T("RX: 0          "), 15);
  pDC->TextOut( 15 , 140, _T("RY: 0          "), 15);
  pDC->TextOut( 15 , 160, _T("RZ: 0          "), 15);

  /*release our window handle */ 
  ReleaseDC(pDC);
}


/*----------------------------------------------------------------------
* Function: CSbtestmfcView::SbButtonPressEvent()
*
* Description:
*    This function receives Virtual 3D Mouse Key (V3DK) information and
*    prints out the info on screen.
*    
*
* Args:
*    int     vkey   // Containts number of Virtual 3D Key pressed 
*
* Return Value:
*    NONE
*
*----------------------------------------------------------------------*/
void
CSbtestmfcView::SbButtonPressEvent(int vkey)
{
  /* Build output string */
  CString msg;
  msg.Format(_T("Key '%s' pressed.    "), s3dm::GetKeyLabel((s3dm::e3dmouse_virtual_key)vkey));

  /* get handle of our window to draw on */
  CDC* pDC;

  pDC = GetDC();  

  /* print key pressed  */
  pDC->TextOut( 0 , 0, msg, 20); 

  /*release our window handle */ 
  ReleaseDC(pDC);

  switch((s3dm::e3dmouse_virtual_key)vkey)
  {
  case s3dm::V3DK_INVALID:  /* Invalid key */
    break;
  case s3dm::V3DK_MENU:    /* Display application's menu */
    break;
  case s3dm::V3DK_FIT:    /* Reset the application's view */
    break;
  case s3dm::V3DK_TOP:    /* Display the Top view */
    break;
  case s3dm::V3DK_LEFT:    /* Display the Left view */
    break;
  case s3dm::V3DK_RIGHT:    /* Display the Right view */
    break;
  case s3dm::V3DK_FRONT:    /* Display the Front view */
    break;
  case s3dm::V3DK_BOTTOM:  /* Display the Bottom view */
    break;
  case s3dm::V3DK_BACK:    /* Display the Back view */
    break;
  case s3dm::V3DK_ROLL_CW:  /* Roll [the view] ClockWise 90 degrees around the screen perpendicular axis */
    break;
  case s3dm::V3DK_ROLL_CCW:  /* Roll [the view] CounterClockWise 90 degrees around the screen perpendicular axis */
    break;
  case s3dm::V3DK_ISO1:    /* Display one ISO view */
    break;
  case s3dm::V3DK_ISO2:    /* Display the other ISO view */
    break;
  case s3dm::V3DK_1:      /* Activate the 1st Programmable Function */
    break;
  case s3dm::V3DK_2:      /* Activate the 2nd Programmable Function */
    break;
  case s3dm::V3DK_3:      /* Activate the 3rd Programmable Function */
    break;
  case s3dm::V3DK_4:      /* Activate the 4th Programmable Function */
    break;
  case s3dm::V3DK_5:      /* Activate the 5th Programmable Function */
    break;
  case s3dm::V3DK_6:      /* Activate the 6th Programmable Function */
    break;
  case s3dm::V3DK_7:      /* Activate the 7th Programmable Function */
    break;
  case s3dm::V3DK_8:      /* Activate the 8th Programmable Function */
    break;
  case s3dm::V3DK_9:      /* Activate the 9th Programmable Function */
    break;
  case s3dm::V3DK_10:    /* Activate the 10th Programmable Function */
    break;
  case s3dm::V3DK_ESC:    /* Simulate an Escape Key */
    break;
  case s3dm::V3DK_ALT:    /* Simulate an Alt Key */
    break;
  case s3dm::V3DK_SHIFT:    /* Simulate a Shift Key */
    break;
  case s3dm::V3DK_CTRL:    /* Simulate a Ctrl Key */
    break;
  case s3dm::V3DK_ROTATE:  /* Toggle Rotations filter on/off */
    break;
  case s3dm::V3DK_PANZOOM:  /* Toggle PanZoom (Translations) filter on/off */
    break;
  case s3dm::V3DK_DOMINANT:  /* Toggle Dominant (single axis filter) on/off */
    break;
  case s3dm::V3DK_PLUS:    /* Increase all axis scale by one level */
    break;
  case s3dm::V3DK_MINUS:    /* Decrease all axis scale by one level */
    break;
  case  s3dm::V3DK_SPIN_CW:  /* Spin [the view] 90 degrees ClockWise around the screen vertical axis */
    break;
  case s3dm::V3DK_SPIN_CCW:  /* Spin [the view] 90 degrees CounterClockWise around the screen vertical axis */
    break;
  case s3dm::V3DK_TILT_CW:  /* Tilt [the view] 90 degrees ClockWise around the screen horizontal axis */
    break;
  case s3dm::V3DK_TILT_CCW:  /* Tilt [the view] 90 degrees CounterClockWise around the screen horizontal axis */
    break;
  default:        /* Unhandled V3DKey */
    break;
  }
}


/*----------------------------------------------------------------------
* Function: CSbtestmfcView::SbButtonReleaseEvent()
*
* Description:
*    This function receives Virtual 3D Mouse Key (V3DK) information and
*    prints out the info on screen.
*    
*
* Args:
*    int     vkey   // Containts number of Virtual 3D Key released 
*
* Return Value:
*    NONE
*
*----------------------------------------------------------------------*/
void CSbtestmfcView::SbButtonReleaseEvent(int vkey)
{
  /* Build output string */
  CString msg;
  msg.Format(_T("Key '%s' released.   "), s3dm::GetKeyLabel((s3dm::e3dmouse_virtual_key)vkey));

  /* get handle of our window to draw on */
  CDC* pDC;

  pDC = GetDC();  

  /* print key released */
  pDC->TextOut( 0 , 0, msg, 20); 

  /*release our window handle */ 
  ReleaseDC(pDC);
}


/*----------------------------------------------------------------------
* Function: SbGetDevicePID()
*
* Description:
*    This function returns the USB PID number for the connected device.
* 
* Args:
*    NONE
*
* Return Value:
*    USB PID number for connected device or zero if an error occurs.
*
*----------------------------------------------------------------------*/
unsigned long CSbtestmfcView::SbGetDevicePID(SiHdl& devHdl)
{
  // Retrive SI device information.
  SiDevInfo info;
  if (SiGetDeviceInfo(devHdl, &info) != SPW_NO_ERROR)
    return 0;

  // Convert SI device type to USB PID number.
  switch (info.devType)
  {
  case SI_SPACEEXPLORER :
    return tdx::eSpaceExplorer;
  case SI_SPACENAVIGATOR_FOR_NOTEBOOKS :
    return tdx::eSpaceNavigatorForNotebooks;
  case SI_SPACENAVIGATOR :
    return tdx::eSpaceNavigator;
  case SI_SPACEPILOT :
    return tdx::eSpacePilot;
  }

  // Newer devices have the number as both SI type and USB PID.
  return (unsigned long)info.devType;
}


/////////////////////////////////////////////////////////////////////////////
// CSbtestmfcView message handlers

LRESULT CSbtestmfcView::On3DMouse( WPARAM wParam, LPARAM lParam )
{
  int            num;      /* number of button returned */
  SiSpwEvent     Event;    /* 3DxWare Event */ 
  SiGetEventData EData;    /* 3DxWare Event Data */

  /* init Window platform specific data for a call to SiGetEvent */
  SiGetEventWinInit(&EData, WM_3DMOUSE, wParam, lParam);

  /* check whether msg was a 3D mouse event and process it */
  if (SiGetEvent (m_DevHdl, 0, &EData, &Event) == SI_IS_EVENT)
  {
    switch (Event.type)
    {
    case SI_MOTION_EVENT:
      SbMotionEvent(&Event);  /* process 3D mouse motion event */     
      break;

    case SI_ZERO_EVENT:
      SbZeroEvent();          /* process 3D mouse zero event */     
      break;

    case  SI_BUTTON_EVENT:
      if ((num = SiButtonPressed (&Event)) != SI_NO_BUTTON)  
      {
        static bool show = true;
        SiSetLEDs(m_DevHdl, show =! show);  // toggle LEDS on any button
        SbButtonPressEvent(num);     /* process button press event */
      }
      if ((num = SiButtonReleased (&Event)) != SI_NO_BUTTON)  
      {
        SbButtonReleaseEvent(num);   /* process button release event */
      }
      break;
    } /* end switch */
  } /* end SiGetEvent */
  return (TRUE);
} /* end of On3DMouse */

// Uncomment the following code if your program must process
// 3DxWare driver events in the PreTransatedMessage handler.
#if 0
/*----------------------------------------------------------------------
* Function: CSbtestmfcView::PreTranslateMessage() 
*
* Description:
*    This function recieves 3D mouse button information and prints out the 
*    info on screen.
*    
*
* Args:
*    MSG*  pMsg    //pointer to the message that we trap and check
*
* Return Value:
*    BOOL  handled //was the message handled?
*
*----------------------------------------------------------------------*/
BOOL CSbtestmfcView::PreTranslateMessage(MSG* pMsg) 
{
  int            num;      /* number of button returned */
  BOOL           handled;  /* is message handled yet */ 
  SiSpwEvent     Event;    /* 3DxWare Event */ 
  SiGetEventData EData;    /* 3DxWare Event Data */

  handled = SPW_FALSE;         /* init handled */

  /* init Window platform specific data for a call to SiGetEvent */
  SiGetEventWinInit(&EData, pMsg->message, pMsg->wParam, pMsg->lParam);

  /* check whether msg was a 3D mouse event and process it */
  if (SiGetEvent (m_DevHdl, 0, &EData, &Event) == SI_IS_EVENT)
  {
    /* figure out what kind of 3D mouse event it is */
    if (Event.type == SI_MOTION_EVENT)
    {
      SbMotionEvent(&Event);  /* process 3D mouse motion event */     
    }
    if (Event.type == SI_ZERO_EVENT)
    {
      SbZeroEvent();          /* process 3D mouse zero event */     
    }
    if (Event.type == SI_BUTTON_EVENT)
    {
      if ((num = SiButtonPressed (&Event)) != SI_NO_BUTTON)  
      {
        SbButtonPressEvent(num);     /* process 3D mouse button event */
      }
      if ((num = SiButtonReleased (&Event)) != SI_NO_BUTTON)  
      {
        SbButtonReleaseEvent(num);     /* process 3D mouse button event */
      }
    }
    handled = SPW_TRUE;            /* 3D mouse event handled */ 
  }

  /* if its not a 3D mouse event, let windows handle it */
  if (handled == SPW_FALSE)
  {
    return CView::PreTranslateMessage(pMsg);
  }
  else
  {
    return handled;
  }  
}
#endif

/*----------------------------------------------------------------------
* Function: CSbtestmfcView::OnCreate() 
*
* Description:
*    This function recieves 3D mouse button information and prints out the 
*    info on screen.
*    
*
* Args: LPCREATESTRUCT lpCreateStruct  //info about the CWnd being created.
*    
* Return Value: 
*    must be 0 to create window, -1 to destroy
*
*----------------------------------------------------------------------*/
int CSbtestmfcView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
  if (CView::OnCreate(lpCreateStruct) == -1)
  {
    return -1;
  }

  int res;  /* Is 3D mouse detected? */

  /* intitialize 3D mouse */
  res = SbInit();

  // if 3D mouse was not detected then print error, close win., exit prog. 
  if (res < 1)
  {
    MessageBox( _T("Sorry - No supported 3Dconnexion device available.\n"),
      NULL, MB_OK);
    if (m_hWnd != NULL)
    {
      DestroyWindow();    // destroy window   
    }
    ExitProcess(1);        // exit program 
  }

  return 0;
}
