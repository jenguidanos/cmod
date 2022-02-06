#pragma once

#include "platform.h"

typedef uint8_t pkt;
typedef struct CModPacket CModPacket;

typedef struct iParser {
  CModPacket* packet;
  pkt* data;

  void (*init)();

  pkt* (*serialize)(CModPacket* packet);
  CModPacket* (*deserialize)(pkt data);
} iParser;
