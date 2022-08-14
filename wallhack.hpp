#pragma once
enum samp_info {
    sampR1 = 0x21A0F8,
    sampR2 = 0x21A100,
    sampR3 = 0x26E8DC,
    sampR4 = 0x26EA0C,
    samp03DL = 0x2ACA24
};
enum presets {
    PrsampR1 = 0x3C5,
    PrsampR2 = 0x3C1,
    PrsampR3 = 0x3D5,
    PrsampR4 = 0x3D5,
    Prsamp03DL = 0x3D5
};


MODULEINFO sampDLLInfo;
HMODULE hSampDLL = GetModuleHandle(L"samp.dll");
DWORD dwSampDLL = reinterpret_cast<DWORD>(hSampDLL);
const char* getSampVer()
{
    GetModuleInformation(GetCurrentProcess(), hSampDLL, &sampDLLInfo, sizeof(sampDLLInfo));
    switch (reinterpret_cast<DWORD>(sampDLLInfo.EntryPoint) - dwSampDLL) {
    case 0x31DF13:    return "R1"; break;
    case 0x3195DD:    return "R2"; break;
    case 0xCC4D0:    return "R3"; break;
    case 0xCBCB0:    return "R4"; break;
    case 0xFDB60:    return "DL"; break;
    }
}


