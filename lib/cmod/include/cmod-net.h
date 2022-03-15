#pragma once

#include "cmod-net-n27.h"
#include "cmod-conf.h"

#if CMOD_NET_ENABLED

#if CMOD_NET_DEFAULT == CMOD_NET_N27
#define CMOD_NET_DEFAULT_MODULE N27
#endif

#ifndef CMOD_NET_DEFAULT_MODULE
#error "CMOD_NET is ENABLED but CMOD_NET_DEFAULT is not defined in conf.h"
#endif

#endif
