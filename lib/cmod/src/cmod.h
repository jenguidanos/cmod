#pragma once

#include "debug.h"
#include "iface/idebug.h"
#include "iface/igps.h"
#include "iface/imessage.h"
#include "iface/inet.h"
#include "message.h"
#include "net.h"
#include "platform.h"

uint8_t init();
uint8_t initDebug();
uint8_t initGps();
uint8_t initMessage();
uint8_t initNet();

typedef struct CMod {
  iDebug *debug;
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

  // debug
  void (*error)(char *message, ...);
  void (*warning)(char *message, ...);
  void (*log)(char *message, ...);
} CMod;

extern CMod cmod;
