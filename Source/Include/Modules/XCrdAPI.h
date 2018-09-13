#pragma once

#include "PCH.h"

typedef int(__cdecl* TXCrdOpenAdapter)(HANDLE* hAdapter);
typedef int(__cdecl* TXCrdCloseAdapter)(HANDLE* hAdapter);

TXCrdOpenAdapter XCrdOpenAdapter;
TXCrdCloseAdapter XCrdCloseAdapter;

bool InitXCrdAPI()
{
	HMODULE hModule = LoadLibraryA("XblAuthConsoleExt.dll");
	if (hModule == NULL) {
		return false;
	}

	XCrdOpenAdapter = (TXCrdOpenAdapter)GetProcAddress(hModule, "XCrdOpenAdapter");
	XCrdCloseAdapter = (TXCrdCloseAdapter)GetProcAddress(hModule, "XCrdCloseAdapter");

	return true;
}
