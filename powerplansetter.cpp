#include <iostream>
#include <windows.h>
#include <powrprof.h>
#include "stdio.h"
#include <ntstatus.h>
#include <string>
#include "powerplansetter.h"

void SetPowerScheme(const GUID* schemeGUID) {
    if (PowerSetActiveScheme(NULL, schemeGUID) == ERROR_SUCCESS) {
        std::cout << "Power scheme changed successfully.\n";
    }
    else {
        std::cerr << "Failed to change power scheme.\n";
    }
}

