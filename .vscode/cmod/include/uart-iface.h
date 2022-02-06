#pragma once

#include "cmod.h"
#include "stdarg.h"
#include "uart-manager.h"

typedef struct iUart {
  struct CModUartConfig *conf;
  int (*write)();
  int (*read)();
  int (*init)(va_list args, ...);
  int (*stop)();
} iUart;
