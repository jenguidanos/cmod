#pragma once

#include "platform.h"
#include "uart-manager.h"

struct CMod {
  struct CModUartManager *uartManager;
};

extern struct CMod cmod;

int cmod_init();
