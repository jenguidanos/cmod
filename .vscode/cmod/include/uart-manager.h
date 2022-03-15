#pragma once

#include "cmod-platform.h"
#include "uart-iface.h"

typedef struct CModUartConfig {
  char* target;
  int tx;
  int rx;
  long baudrate;
  int parity;
  int stopbits;
  int databits;
} CModUartConfig;

struct CModUartManager {
  int (*create)(CModUartConfig config);
};

extern struct CModUartManager cmodUartManager;
