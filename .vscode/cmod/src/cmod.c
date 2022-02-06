#include "cmod.h"

#include "uart-manager.h"

struct CMod cmod;

int cmod_init() {
  cmod.uartManager = &cmodUartManager;
  return 0;
}
