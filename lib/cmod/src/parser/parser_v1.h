#pragma once

#include "iface/iparser.h"

struct CModPacket {
  float lat;
  float lon;
  void (*setLocation)(float lat, float lon);
};

void p1_init();
pkt* p1_serialize(CModPacket* packet);
CModPacket* p1_deserialize(pkt data);
