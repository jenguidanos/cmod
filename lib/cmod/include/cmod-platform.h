#pragma once

/**
 * @file cmod-platform.h
 * @author jenguidanos
 * @brief Defines and includes for the platform specific code.
 * @version 0.1
 * @date 2022-03-15
 *
 * Properties like "ESP_PLATFORM" or "linux" (and so on...) are defined
 * automatically by platformio using platformio.ini. Alternativally, if you are
 * sure of what you are doing, define it in the configuration file cmod-conf.h.
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "cmod-conf.h"

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
