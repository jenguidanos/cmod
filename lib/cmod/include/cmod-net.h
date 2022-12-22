#pragma once

#include "cmod-net-esp32wifi.h"
#include "cmod-conf.h"

#if CMOD_NET_ENABLED

#if CMOD_NET_DEFAULT == CMOD_NET_ESP32WIFI
#define CMOD_NET_DEFAULT_MODULE cmod_net_esp32wifi
#endif

#ifndef CMOD_NET_DEFAULT_MODULE
#error "CMOD_NET is ENABLED but CMOD_NET_DEFAULT is not defined in conf.h"
#endif

#endif
