#include <iostream>
#include <windows.h>
#include <powrprof.h>
#include "stdio.h"
#include <ntstatus.h>
#include <string>
#pragma comment(lib, "powrprof.lib")
#include "powerplansetter.h"
void ClearConsole() {
    system("cls");
}

void DoSpacesinConsole(int HowManySpaces) {
    for (int i = 1; i <= HowManySpaces; ++i) {
        std::cout << "" << std::endl;
    }
}

void drw_txt() {
    std::cout << "Pc Optimization\n";
    DoSpacesinConsole(5);
    std::cout << "1.Change powerplan\n";
    DoSpacesinConsole(1);
    std::cout << "2.Mouse Settings for a litle bit better aim\n";
    DoSpacesinConsole(1);
    std::cout << "3.Disable GameDvr\n";
}


bool SetRegistryValue(HKEY hKeyRoot, LPCSTR subKey, LPCSTR valueName, DWORD data) {
    HKEY hKey;
    LONG result = RegCreateKeyExA(hKeyRoot, subKey, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_SET_VALUE, NULL, &hKey, NULL);

    if (result != ERROR_SUCCESS) {
        std::cerr << "Failed to open/create registry key: " << subKey << " Error: " << result << std::endl;
        ClearConsole();
        drw_txt();
        
    }

    result = RegSetValueExA(hKey, valueName, 0, REG_DWORD, (const BYTE*)&data, sizeof(DWORD));
    RegCloseKey(hKey);

    if (result != ERROR_SUCCESS) {
        std::cerr << "Failed to set registry value: " << valueName << " Error: " << result << std::endl;
        ClearConsole();
        drw_txt();
    }
}







void DisableMouseAcceleration() {
    int mouseParams[3];

    // Retrieve current mouse settings
    if (SystemParametersInfo(SPI_GETMOUSE, 0, mouseParams, 0)) {
        mouseParams[2] = 0; // Set acceleration to 0 (disabled)

        // Apply new settings
        if (SystemParametersInfo(SPI_SETMOUSE, 0, mouseParams, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE)) {
            std::cout << "Mouse acceleration disabled successfully.\n";
        }
        else {
            std::cerr << "Failed to disable mouse acceleration.\n";
        }
    }
    else {
        std::cerr << "Failed to retrieve mouse settings.\n";
    }
}





int main() {
    int input;
    const GUID GUID_HIGH_PERFORMANCE = { 0x8c5e7fda, 0xe8bf, 0x4a96, {0x9a, 0x85, 0xa6, 0x1, 0x2f, 0x54, 0x93, 0x26} };
    SetConsoleOutputCP(CP_UTF8);
    drw_txt();
while (true) {
    std::cin >> input;

    if (input == 1) {
        SetPowerScheme(&GUID_HIGH_PERFORMANCE);
        ClearConsole();
        drw_txt;
    }
    if (input == 2) {
        DisableMouseAcceleration();
        ClearConsole();
        drw_txt();
    }

}

;}






