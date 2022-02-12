#pragma once

#ifdef ESP_PLATFORM
#include <esp_system.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define CMOD_MAIN app_main
#endif

#ifdef linux
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define CMOD_MAIN main
#endif
