#pragma once

#include "iface/igps.h"
#include "iface/imessage.h"
#include "iface/inet.h"
#include "platform.h"

uint8_t init();
uint8_t initNet();
uint8_t initGps();
uint8_t initMessage();

typedef struct CMod {
  iNet *net;
  iGPS *gps;
  iMessage *message;

  uint8_t (*init)();
  uint8_t (*initNet)();
  uint8_t (*initGps)();
  uint8_t (*initMessage)();

  bool (*setNet)(iNet *net);
  bool (*setGps)(iGPS *gps);
  bool (*setMessage)(iMessage *message);
} CMod;

extern CMod cmod;
