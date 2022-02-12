#include "cmod.h"
#include "modules.h"

int main() {
  cmod.init();
  cmod.setNet(&CMOD_NET_DEFAULT_MODULE);
  cmod.setDebug(&CMOD_DEBUG_DEFAULT_MODULE);
  cmod.net->getBattery();
  return 0;
}
