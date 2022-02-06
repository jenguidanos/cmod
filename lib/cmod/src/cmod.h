#pragma once

#include "iface/igps.h"
#include "iface/imessage.h"
#include "iface/inet.h"
#include "iface/iparser.h"
#include "platform.h"

typedef struct CMod {
  iNet *net;
  iGPS *gps;
  iParser *parser;
  iMessage *message;

  uint8_t (*init)();
  uint8_t (*initNet)();
  uint8_t (*initGps)();
  uint8_t (*initMessage)();

  bool (*setNet)(iNet *net);
  bool (*setGps)(iGPS *gps);
  bool (*setParser)(iParser *parser);
  bool (*setMessage)(iMessage *message);
} CMod;

extern CMod cmod;
