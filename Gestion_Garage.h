
// Gestion_Garage.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CGestion_GarageApp:
// See Gestion_Garage.cpp for the implementation of this class
//

class CGestion_GarageApp : public CWinApp
{
public:
	CGestion_GarageApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CGestion_GarageApp theApp;