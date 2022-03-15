#include <unity.h>
#include "cmod.h"

void test_number_is_equal(void) {
    TEST_ASSERT_EQUAL(13, 13);
}

int CMOD_MAIN() {
  UNITY_BEGIN();

  cmod.setDebug(&CMOD_DEBUG_DEFAULT_MODULE);
  cmod.init();
  cmod.setNet(&CMOD_NET_DEFAULT_MODULE);
  cmod.net->getBattery();
  RUN_TEST(test_number_is_equal);

  UNITY_END();
  return 0;
}
