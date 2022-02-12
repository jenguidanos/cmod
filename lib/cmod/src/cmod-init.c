#include "cmod.h"

uint8_t init() {
  uint8_t err = 0;
  uint8_t (*initModules[])() = {initNet, initGps, initMessage, initDebug};

  const uint8_t modulesSize = sizeof(initModules) / sizeof(initModules[0]);

  for (uint8_t i = 0; i < modulesSize; i++) {
    err = initModules[i]();
    if (err != 0) {
      return err;
    }
  }

  cmod.error("[INIT] ...done... ");
  return 0;
}
