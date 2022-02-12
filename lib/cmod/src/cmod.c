#include "cmod.h"

uint8_t init();
uint8_t initNet();
uint8_t initGps();
uint8_t initDebug();
uint8_t initMessage();

bool setNet(iNet *net);
bool setGps(iGPS *gps);
bool setDebug(iDebug *debug);
bool setMessage(iMessage *message);

bool float_promotion_example(float val) { return val > 2.6f; }

CMod cmod = {
    .init = init,
    .initNet = initNet,
    .initGps = initGps,
    .initDebug = initDebug,
    .setNet = setNet,
    .setGps = setGps,
    .setDebug = setDebug,
    .setMessage = setMessage,
};

bool setNet(iNet *net) {
  cmod.net = net;
  return true;
};

bool setGps(iGPS *gps) {
  cmod.gps = gps;
  return true;
};

bool setDebug(iDebug *debug) {
  cmod.debug = debug;
  cmod.error = debug->error;
  cmod.warning = debug->warning;
  cmod.log = debug->log;
  return true;
};

bool setMessage(iMessage *message) {
  cmod.message = message;
  return true;
};

uint8_t initNet() {
  float_promotion_example(23);
  cmod.log("[INIT] Net. ");
  return 0;
}

uint8_t initMessage() {
  cmod.log("[INIT] Message. ");
  return 0;
}

uint8_t initGps() {
  cmod.log("[INIT] GPS. ");
  return 0;
}

uint8_t initDebug() {
  cmod.log("[INIT] GPS. ");
  return 0;
}
