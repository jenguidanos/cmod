#include "cmod.h"

uint8_t init() {
  uint8_t (*initModules[])() = {initDebug, initNet, initGps, initMessage};

  const uint8_t modulesSize = sizeof(initModules) / sizeof(initModules[0]);

  for (uint8_t i = 0; i < modulesSize; i++) {
    uint8_t err = initModules[i]();
    if (err != 0) {
      return err;
    }
  }

  cmod.log->info("[INIT] ...done... ");
  return 0;
}
