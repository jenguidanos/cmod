#pragma once

#include "cmod-platform.h"

typedef struct iNet {
  const int name;

  /**
   * @brief Setup hardware
   * @return  bool
   */
  bool (*init)();

  /**
   * @brief Connects to network
   *
   * A wifi modem will connect to the router, with SSID and password. A cellular
   * modem will connect to the network to obtain GPRS data.
   *
   * @return  bool
   */
  bool (*enable)();

  /**
   * @brief Disconnects from network
   * @return  bool
   */
  bool (*disable)();

  /**
   * @brief Retun the network signal strength
   * @return uint8_t A percentage between 0 and 100
   */
  uint8_t (*getCoverage)();

  /**
   * @brief Open a TCP connection
   *
   */
  bool (*connect)();
  bool (*disconnect)();
  bool (*send)(uint8_t *data);

  bool (*setPowerOn)();
  bool (*setPowerOff)();
  bool (*setStandby)();
} iNet;
