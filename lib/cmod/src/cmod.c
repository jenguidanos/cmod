#include "cmod.h"

uint8_t init();
uint8_t initNet();
uint8_t initGps();
uint8_t initMessage();

bool setNet(iNet *net);
bool setGps(iGPS *gps);
bool setMessage(iMessage *message);

CMod cmod = {
    .init = init,
    .initNet = initNet,
    .initGps = initGps,
    .setNet = setNet,
    .setGps = setGps,
    .setMessage = setMessage,
};

bool setNet(iNet *net) { cmod.net = net; };
bool setGps(iGPS *gps){};
bool setMessage(iMessage *message){};

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
