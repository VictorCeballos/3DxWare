#ifndef CMODULE_HPP_INCLUDED_
#define CMODULE_HPP_INCLUDED_
// cmodule.hpp : Declaration of the module class.
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
// $Id: cmodule.hpp 13201 2016-07-21 10:17:18Z mbonk $
//
// 01/24/13 MSB Initial design
//

// atl
#include <atlbase.h>
#include <atlsync.h>

//stl
#include <memory>

#include "cappwindow.hpp"

// The exe module
class CModule : public ATL::CAtlExeModuleT< CModule >
{
  typedef ATL::CAtlExeModuleT< CModule > _MyBase;
  //construction
public:
  CModule();
  virtual ~CModule();

  HRESULT PreMessageLoop(int nShowCmd) throw ();

private:
  CAppWindow theWindow;
};

extern CModule _theModule;

#endif // CMODULE_HPP_INCLUDED_