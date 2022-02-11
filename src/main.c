#include "cmod.h"
#include "modules.h"

int main() {
  cmod.init();
  cmod.setDebug(&CMOD_DEBUG_DEFAULT_MODULE);
  return 0;
}
