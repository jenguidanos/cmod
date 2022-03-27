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
  cmod.net->init();
  return true;
};

bool setGps(iGPS *gps) {
  cmod.gps = gps;
  cmod.gps->init();
  return true;
};

bool setDebug(iDebug *debug) {
  cmod.log = debug;
  cmod.log->init();
  return true;
};

bool setMessage(iMessage *message) {
  cmod.message = message;
  cmod.message->init();
  return true;
};

uint8_t initNet() {
#if CMOD_NET_ENABLED
  cmod.net = &CMOD_NET_DEFAULT_MODULE;
#else
  cmod.net = &CMOD_NET_FALLBACK_MODULE;
#endif

  return cmod.net->init() ? 0 : 1;
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
  #if CMOD_DEBUG_ENABLED
    cmod.log = &CMOD_DEBUG_DEFAULT_MODULE;
  #else
    cmod.log = &CMOD_DEBUG_FALLBACK_MODULE;
  #endif
  return 0;
}
