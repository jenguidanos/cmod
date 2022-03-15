#include "uart-manager.h"

#include "termios.h"
#include "uart-iface.h"

// Main array of uarts. Initially it's empty. It's filled by
// cmodUartManager.create()
iUart uarts[CMOD_UART_NUMBER_AVAILABLE];

int findEmptyIndex() {
  for (int i = 0; i < CMOD_UART_NUMBER_AVAILABLE; i++) {
    if (uarts[i].conf == NULL) {
      return i;
    }
  }
  return -1;
}

int uart_manager_create(CModUartConfig config) {
  int index = findEmptyIndex();
  printf("Test ok\n");
  if (index < 0) return 0;

  uarts[index].conf = &config;
  printf("created %s", uarts[index].conf->target);

  return index;
}

struct CModUartManager cmodUartManager = {.create = uart_manager_create};
