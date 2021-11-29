// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
DWORD base = (DWORD)GetModuleHandleA(0);

DWORD WINAPI main(void* hModule)
{
    WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(base + 0xC50A8), "\xB0\x01\x90\x90\x90", 5, NULL);
    WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(base + 0xC54BA), "\xB0\x01\x90\x90\x90", 5, NULL);
    return true;
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0x1000, main, hModule, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

