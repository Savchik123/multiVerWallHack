// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <process.h>
#include <windows.h>
#include <iostream>
#include <psapi.h>
#include "wallhack.hpp"


void wallhackMain(PVOID)
{
    static int sampInfo;
    static int presetsInfo;
    if (getSampVer() == "R1")
    {
        sampInfo = samp_info::sampR1;
        presetsInfo = presets::PrsampR1;
    }
    if (getSampVer() == "R2")
    {
        sampInfo = samp_info::sampR2;
        presetsInfo = presets::PrsampR2;
    }
    if (getSampVer() == "R3")
    {
        sampInfo = samp_info::sampR3;
        presetsInfo = presets::PrsampR3;
    }
    if (getSampVer() == "R4")
    {
        sampInfo = samp_info::sampR4;
        presetsInfo = presets::PrsampR4;
    }
    if (getSampVer() == "DL")
    {
        sampInfo = samp_info::samp03DL;
        presetsInfo = presets::Prsamp03DL;
    }
   
        DWORD SampDLL = (DWORD)GetModuleHandleA("samp.dll");
        DWORD* pInfo = (DWORD*)(SampDLL + sampInfo);
        while (*pInfo == 0) Sleep(1000);
        while (*(DWORD*)(*pInfo + presetsInfo) == 0) Sleep(1000);
        BYTE* ThroughWalls = (BYTE*)(*(DWORD*)(*pInfo + presetsInfo) + 0x2F);
        float* fDistance = (float*)((DWORD*)(*(DWORD*)(*pInfo + presetsInfo) + 0x27));
        *fDistance = 1000.0f;
        *ThroughWalls = 0;
}



BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        
        _beginthread(wallhackMain, NULL, NULL);
    }
    return TRUE;
}

