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

bool setNet(iNet *net) { cmod.net = net; };
bool setGps(iGPS *gps) { cmod.gps = gps; };
bool setDebug(iDebug *debug) { cmod.debug = debug; };
bool setMessage(iMessage *message) { cmod.message = message; };

uint8_t initNet() {
  printf("[INIT] Net. ");
  return 0;
}

uint8_t initMessage() {
  printf("[INIT] Message. ");
  return 0;
}

uint8_t initGps() {
  printf("[INIT] GPS. ");
  return 0;
}

uint8_t initDebug() {
  printf("[INIT] GPS. ");
  return 0;
}
