#ifndef action_interface_H_INCLUDED_
#define action_interface_H_INCLUDED_
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

#include "resource.h"

#ifdef __cplusplus
#if (_MSCVER<1600)
#include "cstdint.hpp"
using tdx::uint32_t;
#else
#include <cstdint>
#endif
typedef bool bool_t;
extern "C" {
#else
#if (_MSC_VER<1600)
typedef char int8_t;
typedef unsigned long uint32_t;
#else
#include <stdint.h>
#endif
typedef int8_t bool_t;
#ifndef true
#define true 1
#define false 0
#endif
#endif

#include "si.h"
#include "siappcmd_types.h"

uint32_t write_actions_startup(SiHdl hdl);
uint32_t write_actions_specialchars(SiHdl hdl);
uint32_t write_actions_main(SiHdl hdl);
uint32_t write_multiple_actionsets(SiHdl hdl);

uint32_t activate_actionset_startup(SiHdl hdl);
uint32_t activate_actionset_main(SiHdl hdl);
uint32_t activate_actionset_specialchars(SiHdl hdl);
uint32_t write_images(SiHdl hdl);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // action_interface_H_INCLUDED_