////////////////////////////////////////////////////////////
//
// Moren - 2D RPG Framework
// Copyright (C) 2009 Eugene Alfonso (gin@gtproductions.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
////////////////////////////////////////////////////////////

#ifndef MOREN_WINDATA_HPP
#define MOREN_WINDATA_HPP

#ifdef _WIN32

////////////////////////////////////////////////////////////
// Headers
//
////////////////////////////////////////////////////////////
#include <windows.h>

/////////////////////////////////////////////////
/// WinMainData struct holds data from WinMain()
///
/////////////////////////////////////////////////
struct WinMainData
{
	HINSTANCE	hInstance;
	HINSTANCE	hPrevInstance;
	LPSTR		lpCmdLine;
	int			nCmdShow;
};

#endif

#endif // MOREN_WINDATA_HPP