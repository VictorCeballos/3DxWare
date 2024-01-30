========================================================================
    WIN32 APPLICATION : actions_settings_sample Project Overview
========================================================================

The actions_settings sample demonstrates the use of the action interface extension of
the 3Dconnexion 3DxWare SDK.

The action interface extension allows the application to use the 3Dconnexion Properties
dialog to support assigning commands (actions) to 3D Mouse buttons and configuring
the 3D mouse for use within the application.

The sample defines three actions sets that represent the actions a user can invoke in a fictive
application corresponding to the start that application is in. In this sample,

The "Startup" action set represents the actions which are available when the application starts up.
The "Main" action set contains the actions available under normal working conditions.
The "Special Chars" action set contains the actions in soem special editing mode the application might have.

When the sample initializes it exports and activates the commands of the startup action set.
The sample allows the user to activate any one of the "Startup", "Main" and "Special Chars" action sets.
Activating an action set will be echoed in the "Buttons" dialog of the "3Dconnexion Properties" application.
The commands/actions of the active actionset will be available for assignment to a button in the button flyout 
under "Action Interface". Button assignments are saved on a per active actionset basis.

This sample project has dependencies on the 3Dconnexion 3DxWare SDK, ATL and WTL.
The sample requires 3DxWare 10.2 or later.

To build the project you may need to adjust the macros WTL_ROOT in wtl.props
and _3DXWARE_ROOT in 3dxware.props to where you have installed the corresponding SDKs.

For 3Dconnexion SDK support please contact us via the 3Dconnexion developer forum on
www.3Dconnexion.com/forum. We appreciation your interest in supporting our range of devices 
and would be happy to hear from you.

The Development Team

Copyright © 2010-2018 3Dconnexion. All rights reserved.




