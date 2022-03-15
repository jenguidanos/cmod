#pragma once

#include "cmod-debug.h"
#include "cmod-message.h"
#include "cmod-net.h"
#include "cmod-platform.h"
#include "iface/idebug.h"
#include "iface/igps.h"
#include "iface/imessage.h"
#include "iface/inet.h"

uint8_t init();
uint8_t initDebug();
uint8_t initGps();
uint8_t initMessage();
uint8_t initNet();

typedef struct CMod {
  iDebug *log;
  iGPS *gps;
  iMessage *message;
  iNet *net;

  uint8_t (*init)();
  uint8_t (*initDebug)();
  uint8_t (*initGps)();
  uint8_t (*initMessage)();
  uint8_t (*initNet)();

  bool (*setDebug)(iDebug *debug);
  bool (*setGps)(iGPS *gps);
  bool (*setMessage)(iMessage *message);
  bool (*setNet)(iNet *net);
} CMod;

extern CMod cmod;
