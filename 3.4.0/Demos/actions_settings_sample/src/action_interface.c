// test_action_interface.cpp
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
#include "action_interface.h"
#include "siappcmd.h"

#ifdef __cplusplus
extern "C" {
#endif

  // Contents of Macro_Paste.png file from 3DxWinCore driver installation.
  const uint8_t raw_image_data[] =
  {
    0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d,
    0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x18,
    0x08, 0x06, 0x00, 0x00, 0x00, 0xe0, 0x77, 0x3d, 0xf8, 0x00, 0x00, 0x00,
    0x19, 0x74, 0x45, 0x58, 0x74, 0x53, 0x6f, 0x66, 0x74, 0x77, 0x61, 0x72,
    0x65, 0x00, 0x41, 0x64, 0x6f, 0x62, 0x65, 0x20, 0x49, 0x6d, 0x61, 0x67,
    0x65, 0x52, 0x65, 0x61, 0x64, 0x79, 0x71, 0xc9, 0x65, 0x3c, 0x00, 0x00,
    0x00, 0x7c, 0x49, 0x44, 0x41, 0x54, 0x78, 0xda, 0xec, 0x96, 0x41, 0x0a,
    0xc0, 0x20, 0x0c, 0x04, 0x4d, 0xf1, 0x89, 0xf1, 0x2f, 0x3e, 0xc1, 0xbf,
    0xf8, 0xc8, 0x6d, 0xed, 0xa1, 0x88, 0x50, 0x63, 0x42, 0x3d, 0x35, 0x7b,
    0x90, 0x04, 0x16, 0x66, 0x93, 0x43, 0x90, 0x98, 0x39, 0x74, 0x42, 0xd0,
    0x89, 0x24, 0x43, 0x6c, 0x4f, 0xce, 0xf9, 0x6e, 0x4a, 0x29, 0x4f, 0x2d,
    0xa9, 0xf7, 0xb6, 0x7a, 0x06, 0xc0, 0xcc, 0x20, 0x40, 0x20, 0x4d, 0x43,
    0xd7, 0x8a, 0xb0, 0x9a, 0x7a, 0x36, 0xcd, 0x1b, 0xe0, 0x08, 0x9b, 0x15,
    0x15, 0x09, 0x25, 0xc1, 0x0c, 0x68, 0xaa, 0xb5, 0x92, 0x36, 0x7d, 0x4a,
    0x09, 0xdb, 0x57, 0xe4, 0x00, 0x07, 0x38, 0xc0, 0x01, 0xbf, 0x00, 0x44,
    0xc5, 0xbd, 0x37, 0x03, 0x56, 0xee, 0x3c, 0xac, 0x00, 0x1a, 0xbe, 0x2d,
    0x9f, 0x03, 0x4e, 0x01, 0x06, 0x00, 0x31, 0x85, 0x20, 0x8b, 0xb1, 0xca,
    0xfc, 0xe3, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42,
    0x60, 0x82
  };

  ////////////////////////////////////////////////////////////////////////////////////
  // The following are the equivalent of the menus in an application window (not this
  // sample). These are defined as SiActionNodeEx_t types i.e. linked lists. The lists
  // are defined here as data to illustrate the structure more easily. The lists could
  // be constructed at runtime by iterating over the menus and menu items.
  // Items in a menu that result in an application command being invoke have a node type
  // SI_ACTION_NODE and are the leaves of the tree. Items in a menu that open sub menus
  // have a node type SI_CATEGORY_NODE and the children member of SiActionNodeEx_t
  // point to the child menu items.

  // The menu items of the startup menu
  SiActionNodeEx_t startup_actions[] =
  {
    { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &startup_actions[1], NULL, "FN_FILE_NEW", "New...", "FN_FILE_NEW tool tip" }
    ,{ sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &startup_actions[2], NULL, "FN_FILE_OPEN", "Open...", "FN_FILE_OPEN tool tip" }
    ,{ sizeof(SiActionNodeEx_t), SI_ACTION_NODE, NULL            , NULL, "FN_FILE_EXIT", "Exit", "FN_FILE_EXIT tool tip" }
  };

  // The menu items of the file menu
  SiActionNodeEx_t file_actions[] =
  {
    {sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &file_actions[1], NULL, "FN_FILE_NEW", "New...", "FN_FILE_NEW tool tip" }
    , { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &file_actions[2], NULL, "FN_FILE_OPEN", "Open...", "FN_FILE_OPEN tool tip" }
    , { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &file_actions[3], NULL, "FN_FILE_CLOSE", "Close", "FN_FILE_CLOSE tool tip" }
    , { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &file_actions[4], NULL, "FN_FILE_SAVE", "Save", "FN_FILE_SAVE tool tip" }
    , { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &file_actions[5], NULL, "FN_FILE_SAVE_AS", "Save As...", "FN_FILE_SAVE_AS tool tip" }
    , { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &file_actions[6], NULL, "FN_FILE_PRINT", "Print...", "FN_FILE_PRINT tool tip" }
    , { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, NULL            , NULL, "FN_FILE_EXIT", "Exit", "FN_FILE_EXIT tool tip" }
  };

  // The menu items of the find submenu (see the edit menu below)
  SiActionNodeEx_t find_actions[] =
  {
      { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &find_actions[1], NULL, "FN_QUICK_FIND", "Quick Find", "FN_QUICK_FIND tool tip" }
      , { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &find_actions[2], NULL, "FN_QUICK_REPLACE", "Quick Replace", "FN_QUICK_REPLACE tool tip" }
      , { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &find_actions[3], NULL, "FN_FIND_IN_FILES", "Find in Files", "FN_FIND_IN_FILES tool tip" }
      , { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, NULL            , NULL, "FN_REPLACE_IN_FILES", "Replace in Files", "FN_REPLACE_IN_FILES tool tip" }
  };

  // The menu items of the edit menu
  // Category nodes can be thought of as menus or sub-menus. A category node is simply a means of
  // grouping action and further category nodes in a meaningful manner.
  SiActionNodeEx_t edit_actions[] =
  {
    { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &edit_actions[1], NULL, "FN_EDIT_UNDO", "Undo", "FN_EDIT_UNDO tool tip" }
    , { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &edit_actions[2], NULL, "FN_EDIT_REDO", "Redo", "FN_EDIT_REDO tool tip" }
    , { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &edit_actions[3], NULL, "FN_EDIT_CUT", "Cut", "FN_EDIT_CUT tool tip" }
    , { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &edit_actions[4], NULL, "FN_EDIT_COPY", "Copy", "FN_EDIT_COPY tool tip" }
    , { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &edit_actions[5], NULL, "FN_EDIT_PASTE", "Paste", "FN_EDIT_PASTE tool tip" }
    , { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &edit_actions[6], NULL, "FN_EDIT_DELETE", "Delete", "FN_EDIT_DELETE tool tip" }
    , { sizeof(SiActionNodeEx_t), SI_CATEGORY_NODE, &edit_actions[7], &find_actions[0], "CATID_FIND_AND_REPLACE", "Find and Replace", "CATID_FIND_AND_REPLACE tool tip" }
    , { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, NULL            , NULL, "FN_EDIT_GO_TO", "Go To...", "FN_EDIT_GO_TO tool tip" }
  };

  // The menu items of the tools menu
  SiActionNodeEx_t tools_actions[] =
  {
    { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &tools_actions[1], NULL, "FN_TOOLS_CUSTOMIZE", "Customize...", "FN_TOOLS_CUSTOMIZE tool tip" }
    , { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, NULL           , NULL, "FN_TOOLS_OPTIONS", "Options...", "FN_TOOLS_OPTIONS tool tip" }
  };

  // The menu items of the help menu
  SiActionNodeEx_t help_actions[] =
  {
    { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &help_actions[1], NULL, "FN_HELP_VIEW_HELP", "View Help", "FN_HELP_VIEW_HELP tool tip" }
    , { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &help_actions[2], NULL, "FN_HELP_CONTACT_US", "Contact Us", "FN_HELP_CONTACT_US tool tip" }
    , { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &help_actions[3], NULL, "FN_HELP_REGISTER_PRODUCT", "Register Product", "FN_HELP_REGISTER_PRODUCT tool tip" }
    , { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &help_actions[4], NULL, "FN_HELP_CHECK_FOR_UPDATES", "Check for Updates", "FN_HELP_CHECK_FOR_UPDATES tool tip" }
    , { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, NULL            , NULL, "FN_HELP_ABOUT", "About...", "FN_HELP_ABOUT tool tip" }
  };

  // The menu items of the special characters menu
  SiActionNodeEx_t special_characters_actions[] =
  {
    { sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &special_characters_actions[1], NULL, "FN_QUOTE_CHAR\"", "Quote Char \"", "FN_QUOTE_CHAR tool tip" }
    ,{ sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &special_characters_actions[2], NULL, "FN_SINGLE_QUOTE_CHAR\'", "Single Quote Char \'", "FN_SINGLE_QUOTE_CHAR tool tip" }
    ,{ sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &special_characters_actions[3], NULL, "FN_AMPERSAND_CHAR&", "Ampersand Char &", "FN_AMPERSAND_CHAR tool tip" }
    ,{ sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &special_characters_actions[4], NULL, "FN_LESSTHAN_CHAR<", "Less than char <", "FN_LESSTHAN_CHAR tool tip" }
    ,{ sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &special_characters_actions[5], NULL, "FN_GREATERTHAN_CHAR>", "Greater than char >", "FN_GREATERTHAN_CHAR tool tip" }
    ,{ sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &special_characters_actions[6], NULL, "FN_PERCENT_CHAR%", "Percent char %", "FN_PERCENT_CHAR tool tip" }
    ,{ sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &special_characters_actions[7], NULL, "FN_PERCENT_CHAR%123", "Percent char 123 %123", "FN_PERCENT_CHAR tool tip" }
    ,{ sizeof(SiActionNodeEx_t), SI_ACTION_NODE, &special_characters_actions[8], NULL, "FN_DOLLAR_CHAR$", "Dollar char $", "FN_DOLLAR_CHAR$ tool tip" }
    ,{ sizeof(SiActionNodeEx_t), SI_ACTION_NODE, NULL, NULL, "FN_DOLLAR_CHAR$123", "Dollar char 123 $123", "FN_DOLLAR_CHAR$123 tool tip" }
  };

  ////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Category nodes can be thought of as menus or sub-menus. A category node is simply a means of
  // grouping action and further category nodes in a meaningful manner.

  // The catergories/grouping for the 'Startup' menubar
  SiActionNodeEx_t Startup_categories[] =
  {
    { sizeof(SiActionNodeEx_t), SI_CATEGORY_NODE, &Startup_categories[1],   &startup_actions[0],   "CATID_FILE","File", NULL }
    ,{ sizeof(SiActionNodeEx_t), SI_CATEGORY_NODE, &Startup_categories[2], &tools_actions[0],  "CATID_TOOLS","Tools", NULL }
    ,{ sizeof(SiActionNodeEx_t), SI_CATEGORY_NODE, NULL,                &help_actions[0], "CATID_HELP","Help", NULL }
  };

  // The catergories/grouping for the 'Special chars' menubar
  SiActionNodeEx_t SpecialChar_categories[] =
  {
    { sizeof(SiActionNodeEx_t), SI_CATEGORY_NODE, &SpecialChar_categories[1],   &special_characters_actions[0],   "CATID_SPECIAL_CHAR","Special Characters", NULL}
    ,{ sizeof(SiActionNodeEx_t), SI_CATEGORY_NODE, &SpecialChar_categories[2], &tools_actions[0],  "CATID_TOOLS","Tools", NULL }
    ,{ sizeof(SiActionNodeEx_t), SI_CATEGORY_NODE, NULL,                &help_actions[0], "CATID_HELP","Help", NULL }
  };

  // The catergories/grouping for the 'main' menubar
  SiActionNodeEx_t Main_categories[] =
  {
    { sizeof(SiActionNodeEx_t), SI_CATEGORY_NODE, &Main_categories[1],   &file_actions[0],   "CATID_FILE","File", NULL }
    , { sizeof(SiActionNodeEx_t), SI_CATEGORY_NODE, &Main_categories[2], &edit_actions[0],   "CATID_EDIT","Edit", NULL }
    , { sizeof(SiActionNodeEx_t), SI_CATEGORY_NODE, &Main_categories[3], &tools_actions[0],  "CATID_TOOLS","Tools", NULL }
    , { sizeof(SiActionNodeEx_t), SI_CATEGORY_NODE, NULL,                &help_actions[0],   "CATID_HELP","Help", NULL }
  };

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Action set nodes could be thought of as menu bars. A program may change state so that only a subset of the
  // the commands (menus/menu items) are available to the user. An example might be the sketch mode in a CAD
  // application. For the sketch mode one might decide to define a set of commands that are available to the
  // 3Dconnexion Properties dialog for the button assignments.
  // The available category and action nodes would, in this case, be defined under a "SKETCH" action set node
  // and the action set activated when the application switches to the sketching state.
  // The commands that a user can assign to a device button or activate by pressing a device button are limited
  // to those commands in the active action set. Using actions sets allows the user to configure the device
  // buttons per action set. When an action set is activated, the driver switches the device button assignments
  // to that assigned when the action set was active.

  // In this sample we define three action sets

  SiActionNodeEx_t action_set_startup =
  { sizeof(SiActionNodeEx_t), SI_ACTIONSET_NODE, NULL, &Startup_categories[0], "startup_action_set_id", "Startup Mode", NULL };

  SiActionNodeEx_t action_set_specialchars =
  { sizeof(SiActionNodeEx_t), SI_ACTIONSET_NODE, NULL, &SpecialChar_categories[0], "specialchars_action_set_id", "Special Chars Mode", NULL };

  SiActionNodeEx_t action_set_main =
  { sizeof(SiActionNodeEx_t), SI_ACTIONSET_NODE, NULL, &Main_categories[0], "main_action_set_id", "Main Mode", NULL };

  // Note: It is also possible to communicate multiple actions sets to the driver in one data blob.
  SiActionNodeEx_t multiple_action_sets[] =
  {
    { sizeof(SiActionNodeEx_t), SI_ACTIONSET_NODE, &multiple_action_sets[1], &SpecialChar_categories[0], "specialchars_action_set_id", "Special Chars Mode", NULL }
    , { sizeof(SiActionNodeEx_t), SI_ACTIONSET_NODE, &multiple_action_sets[2], &Main_categories[0], "main_action_set_id", "Main Mode", NULL }
    , { sizeof(SiActionNodeEx_t), SI_ACTIONSET_NODE, NULL, &Startup_categories[0], "startup_action_set_id", "Startup Mode", NULL }
  };

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Its a advisable to associate images with actions for devices that support icons as well as for the
  // 3Dconnnexion property editor SmartUI. Using the same icons that are displayed on menu- and toolbars allows
  // the user easily recognize the action.
  // The icons / images are passed to the driver as an array of SiImage_t structures. SiImage_t contains a union
  // which describes the image and an id which associates the image with the action in the SiActionNodeEx_t with
  // the same id. Images can be either in separate files, as resources in resource dlls or data.
  //
  // Note images embedded in a resource dll (e_resource_file type) use the "#" microsoft string notation
  // i.e. RT_BITMAP = "#2", RT_ICON = "#3", resource id with a value of MAKEINTRESOURCE(216) = "#216".
  //
  // Also note the first array element is overwritten in the write_image() function. This is done avoid a
  // compiler warning during the initialization of a union.
  //
  // In this example, a system dll file (ieframe.dll) which should be available in all systems is used and we
  // also assume the driver is installed in the default location. It may be necessary to edit the paths to
  // adapt this sample to the system's configuration.
  SiImage_t action_images[] =
  {
     { sizeof(SiImage_t), e_image,  "", {""}} // To be overwritten (read explanation above).
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_FILE_NEW", { "c:/windows/system32/ieframe.dll", "#216", "#2", 11} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_FILE_OPEN", { "c:/windows/system32/ieframe.dll", "#216", "#2", 12} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_FILE_CLOSE", { "c:/windows/system32/ieframe.dll", "#216", "#2", 15} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_FILE_SAVE", { "c:/windows/system32/ieframe.dll", "#216", "#2", 13} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_FILE_SAVE_AS", { "c:/windows/system32/ieframe.dll", "#216", "#2", 13} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_FILE_PRINT", { "c:/windows/system32/ieframe.dll", "#216", "#2", 19} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_FILE_EXIT", { "c:/windows/system32/ieframe.dll", "#216", "#2", 10} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_QUOTE_CHAR", { "c:/windows/system32/ieframe.dll", "#806", "IMAGE"} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_SINGLE_QUOTE_CHAR\'", { "c:/windows/system32/ieframe.dll", "#806", "IMAGE"} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_AMPERSAND_CHAR&", { "c:/windows/system32/ieframe.dll", "#806", "IMAGE"} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_LESSTHAN_CHAR<", { "c:/windows/system32/ieframe.dll", "#806", "IMAGE"} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_GREATERTHAN_CHAR>", { "c:/windows/system32/ieframe.dll", "#806", "IMAGE"} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_PERCENT_CHAR%", { "c:/windows/system32/ieframe.dll", "#806", "IMAGE"} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_PERCENT_CHAR%123", { "c:/windows/system32/ieframe.dll", "#806", "IMAGE"} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_DOLLAR_CHAR$", { "c:/windows/system32/ieframe.dll", "#806", "IMAGE"} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_DOLLAR_CHAR$123", { "c:/windows/system32/ieframe.dll", "#806", "IMAGE"} }
    ,{ sizeof(SiImage_t), e_image_file,  "FN_EDIT_UNDO", { "C:/Program Files/3Dconnexion/3DxWare/3DxWinCore64/Cfg/Images/3DxService/Macro_Undo.png"} }
    ,{ sizeof(SiImage_t), e_image_file,  "FN_EDIT_REDO", { "C:/Program Files/3Dconnexion/3DxWare/3DxWinCore64/Cfg/Images/3DxService/Macro_Redo.png"} }
    ,{ sizeof(SiImage_t), e_image_file,  "FN_EDIT_CUT", { "C:/Program Files/3Dconnexion/3DxWare/3DxWinCore64/Cfg/Images/3DxService/Macro_Cut.png"} }
    ,{ sizeof(SiImage_t), e_image_file,  "FN_EDIT_COPY", { "C:/Program Files/3Dconnexion/3DxWare/3DxWinCore64/Cfg/Images/3DxService/Macro_Copy.png"} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_EDIT_DELETE", { "c:/windows/system32/ieframe.dll", "#216", "#2", 10} }
    ,{ sizeof(SiImage_t), e_resource_file,  "CATID_FIND_AND_REPLACE", { "c:/windows/system32/ieframe.dll", "#216", "#2", 18} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_EDIT_GO_TO", { "c:/windows/system32/ieframe.dll", "#216", "#2", 45} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_TOOLS_CUSTOMIZE", { "c:/windows/system32/ieframe.dll", "#216", "#2", 4} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_TOOLS_OPTIONS", { "c:/windows/system32/ieframe.dll", "#216", "#2", 4} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_QUICK_FIND", { "c:/windows/system32/ieframe.dll", "#216", "#2", 17} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_FIND_IN_FILES", { "c:/windows/system32/ieframe.dll", "#216", "#2", 14} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_HELP_VIEW_HELP", { "c:/windows/system32/ieframe.dll", "#216", "#2", 16} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_HELP_CONTACT_US", { "c:/windows/system32/ieframe.dll", "#216", "#2", 38} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_HELP_REGISTER_PRODUCT", { "c:/windows/system32/ieframe.dll", "#216", "#2", 3} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_HELP_CHECK_FOR_UPDATES", { "c:/windows/system32/ieframe.dll", "#216", "#2", 29} }
    ,{ sizeof(SiImage_t), e_resource_file,  "FN_HELP_ABOUT", { "c:/windows/system32/ieframe.dll", "#216", "#2", 2} }
  };

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // this function communicates the "Special Char Mode" action set to the driver. Normally this only needs
  // to be done once, unless the contents of the action set changes.
  uint32_t write_actions_specialchars(SiHdl hdl)
  {
    return SiAppCmdWriteActions(hdl, &action_set_specialchars);
  }

  // this function communicates just the "Main Mode" action set to the driver. Normally this only needs
  // to be done once, unless the contents of the action set changes.
  uint32_t write_actions_main(SiHdl hdl)
  {
    return SiAppCmdWriteActions(hdl, &action_set_main);
  }

  // this function communicates multiple action sets at once to the driver.
  uint32_t write_multiple_actionsets(SiHdl hdl)
  {
    return SiAppCmdWriteActions(hdl, &multiple_action_sets[0]);
  }

  // this function sets the "Startup Mode" action set as the active action set.
  // The side effect is to switch the button configuration of the device to the one
  // configured when the "Special Char Mode" action set was active.
  uint32_t activate_actionset_startup(SiHdl hdl)
  {
    return SiAppCmdActivateActionSet(hdl, action_set_startup.id);
  }

  // this function sets the "Special Char Mode" action set as the active action set.
  // The side effect is to switch the button configuration of the device to the one
  // configured when the "Special Char Mode" action set was active.
  uint32_t activate_actionset_specialchars(SiHdl hdl)
  {
    return SiAppCmdActivateActionSet(hdl, action_set_specialchars.id);
  }

  // this function sets the "Main Mode" action set as the active action set.
  // The side effect is to switch the button configuration of the device to the one
  // configured when the "Main Mode" action set was active.
  uint32_t activate_actionset_main(SiHdl hdl)
  {
    return SiAppCmdActivateActionSet(hdl, action_set_main.id);
  }

  // communicate the images to the driver
  uint32_t write_images(SiHdl hdl)
  {
    // Overwrite first array element to exemplify the export of a command icon using a raw image data buffer.
    action_images[0].size = sizeof(SiImage_t);
    action_images[0].type = e_image;
    action_images[0].id = "FN_EDIT_PASTE";
    action_images[0].image.data = raw_image_data;
    action_images[0].image.size = sizeof(raw_image_data) / sizeof(raw_image_data[0]);
    action_images[0].image.index = 0;

    return SiAppCmdWriteActionImages(hdl, action_images, sizeof(action_images) / sizeof(action_images[0]));
  }

#ifdef __cplusplus
} // extern "C"
#endif