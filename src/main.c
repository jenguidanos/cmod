#include "cmod-message.h"
#include "cmod-net-n27.h"
#include "cmod.h"

int main() {
  cmod.setNet(&N27);
  cmod.init();
  cmod.net->enable();
  // cmod.setMessage(&message);

  return 0;
}
