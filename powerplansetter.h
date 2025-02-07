#include <iostream>
#include <windows.h>
#include <powrprof.h>
#include "stdio.h"
#include <ntstatus.h>
#include <string>

void SetPowerScheme(const GUID* schemeGUID);
