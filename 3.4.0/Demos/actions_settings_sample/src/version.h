#ifndef _VERSION_H_INCLUDED
#define _VERSION_H_INCLUDED
// version.h
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
#include "subwcrev.h"
///////////////////////////////////////////////////////////////////////////////
// History:
//
// $Id: version.h 13201 2016-07-21 10:17:18Z mbonk $
//
///////////////////////////////////////////////////////////////////////////////

// Current version
#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define VERSION_MICRO SVN_BUILD_NUMBER

#define STRINGIZER(arg)       #arg
#define MACROSTRINGIZER(arg)  STRINGIZER(arg)

#define FILE_VERSION          VERSION_MAJOR,VERSION_MINOR,VERSION_MICRO,SVN_WCREV
#define PRODUCT_VERSION       VERSION_MAJOR,VERSION_MINOR,VERSION_MICRO,SVN_WCREV

//Defines used in the 3dxcontrol.rc file for version control
#define COMPANY_NAME_STR      "3Dconnexion"
#define FILE_DESCRIPTION_STR  "Action Interface"
#define FILE_VERSION_STR      MACROSTRINGIZER(VERSION_MAJOR.VERSION_MINOR.VERSION_MICRO.SVN_WCREV)
#define INTERNAL_NAME_STR     "actions_settings_sample"
#define LEGAL_COPYRIGHT_STR   SVN_COPYRIGHT
#define LEGAL_TRADEMARKS_STR  "All registered trademarks acknowledged."
#define ORIGINAL_FILENAME_STR "actions_settings_sample"
#define PRODUCT_NAME_STR      "3Dconnexion SDK Samples"
#define PRODUCT_VERSION_STR   MACROSTRINGIZER(VERSION_MAJOR.VERSION_MINOR.VERSION_MICRO.SVN_WCREV)

#define RELEASE_NOTE_STR    "Released: "MACROSTRINGIZER(SVN_WCNOW)"\r\nRevision: "MACROSTRINGIZER(SVN_WCRANGE)

#endif //_VERSION_H_INCLUDED
