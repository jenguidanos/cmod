#include "cmod.h"

int CMOD_MAIN() {
  cmod.setDebug(&CMOD_DEBUG_DEFAULT_MODULE);
  cmod.init();
  cmod.setNet(&CMOD_NET_DEFAULT_MODULE);
  cmod.net->getBattery();
  return 0;
}
