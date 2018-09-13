#pragma once

#include "PCH.h"

typedef int(__cdecl* XblaInitializeDef)();
typedef int(__cdecl* XblaGetConsoleIdDef)(void* lpConsoleIdBuffer);
typedef int(__cdecl* XblaGetConsoleSerialNumberDef)(void* lpConsoleSerialBuffer);

XblaInitializeDef XblaInitialize;
XblaGetConsoleIdDef XblaGetConsoleId;
XblaGetConsoleSerialNumberDef XblaGetConsoleSerialNumber;

bool InitXblAuthConsoleExt()
{
	HMODULE hModule = LoadLibraryA("XblAuthConsoleExt.dll");
	if (hModule == NULL) {
		return false;
	}

	XblaInitialize = (XblaInitializeDef)GetProcAddress(hModule, "XblaInitialize");
	XblaGetConsoleId = (XblaGetConsoleIdDef)GetProcAddress(hModule, "XblaGetConsoleId");
	XblaGetConsoleSerialNumber = (XblaGetConsoleSerialNumberDef)GetProcAddress(hModule, "XblaGetConsoleSerialNumber");

	return true;
}