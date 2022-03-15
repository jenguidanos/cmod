#pragma once

#include "cmod-debug-printf.h"
#include "cmod-conf.h"

#if CMOD_DEBUG_ENABLED

#if CMOD_DEBUG_DEFAULT == CMOD_DEBUG_PRINTF
#define CMOD_DEBUG_DEFAULT_MODULE cmodDebugPrintf
#endif

#ifndef CMOD_DEBUG_DEFAULT_MODULE
#error "CMOD_DEBUG is ENABLED but CMOD_DEBUG_DEFAULT is not defined in conf.h"
#endif

#endif
