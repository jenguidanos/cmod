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
  cmod.log = debug;
  return true;
};

bool setMessage(iMessage *message) {
  cmod.message = message;
  return true;
};

uint8_t initNet() {
  cmod.log->info("[INIT] Net. ");
  return 0;
}

uint8_t initMessage() {
  cmod.log->info("[INIT] Message. ");
  return 0;
}

uint8_t initGps() {
  cmod.log->info("[INIT] GPS. ");
  return 0;
}

uint8_t initDebug() {
  cmod.log->info("[INIT] GPS. ");
  return 0;
}
