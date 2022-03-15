#pragma once

#include "cmod-platform.h"

typedef struct Location {
  float lat;
  float lon;
  uint16_t sog;
  uint16_t cog;
  uint8_t sats;
  uint8_t hdop;
  uint8_t vdop;
} Location;

typedef struct iGPS {
  int name;
  Location last;

  uint8_t (*init)();
  uint8_t (*read)();
} iGPS;
