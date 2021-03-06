#pragma once

#include "cmod-platform.h"

enum NetProtocol { TCP = 1, UDP };

typedef struct iNet {

  enum NetProtocol protocol;
  const int name;
  char id[20];
  bool (*setId)(char *id);

 bool (*init)();

  /**
   * @brief Realiza una conexión a la red
   *
   * @return  bool    [return description]
   */
  bool (*enable)();
  bool (*disable)();
  uint8_t (*getCoverage)();

  bool (*connect)();
  bool (*disconnect)();
  bool (*send)(uint8_t *data);

  bool (*setPowerOn)();
  bool (*setPowerOff)();
  bool (*setStandby)();
  float (*getBattery)();
} iNet;
