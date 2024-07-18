#define _WIN32_WINNT _WIN32_WINNT_WIN10
#include <initguid.h>
#include <windows.h>
#include <appmodel.h>
#include <shobjidl.h>

int WinMainCRTStartup()
{
    CoInitialize(NULL);
    IPackageDebugSettings *pPackageDebugSettings = NULL;
    CoCreateInstance(&CLSID_PackageDebugSettings, NULL, CLSCTX_INPROC_SERVER, &IID_IPackageDebugSettings,
                     (LPVOID *)&pPackageDebugSettings);
    PWSTR packageFamilyNames[] = {L"Microsoft.MinecraftUWP_8wekyb3d8bbwe",
                                  L"Microsoft.MinecraftWindowsBeta_8wekyb3d8bbwe"};

    for (int i = 0; i < 2; i++)
    {
        UINT32 count = 0, bufferLength = 0;
        if (GetPackagesByPackageFamily(packageFamilyNames[i], &count, NULL, &bufferLength, NULL) !=
            ERROR_INSUFFICIENT_BUFFER)
            continue;

        PWSTR packageFullName = HeapAlloc(GetProcessHeap(), 0, sizeof(WCHAR) * bufferLength);

        GetPackagesByPackageFamily(packageFamilyNames[i], &count, HeapAlloc(GetProcessHeap(), 0, sizeof(PWSTR) * count),
                                   &bufferLength, packageFullName);
        pPackageDebugSettings->lpVtbl->EnableDebugging(pPackageDebugSettings, packageFullName, NULL, NULL);
    }

    pPackageDebugSettings->lpVtbl->Release(pPackageDebugSettings);
    CoUninitialize();
    ExitProcess(0);
    return 0;
}