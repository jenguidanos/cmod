#pragma once

#include "cmod-platform.h"

/**
 * @brief Debug level types definition
 *
 * The order matters, first error, last info
 */
typedef enum { CMOD_ERROR, CMOD_WARNING, CMOD_INFO } iDebugLevelType;

/**
 * @brief Interface for debug object
 *
 * This interface is used to print debug messages with log level. There are 3
 * log levels: error, warn and info.
 *
 * On some systems native's printf module is enough (used in cmod-debug-printf),
 * on others you may need to delegate on other interfaces, like UART.
 */
typedef struct iDebug {
  /** @brief Debug mode. Should be changed with \ref setlevel */
  int level;

  /**
   * @brief Initialize the debug interface
   *
   * Use this method to setup a debug interface, e.g configure an UART port.
   */
  int (*init)();

  /**
   * @brief Change the debug level
   *
   * This method should be called on init to setup the default debug level.
   * It should be possible to change it at any time during runtime.
   *
   * @param level
   */
  int (*setLevel)(iDebugLevelType level);

  /**
   * @brief Print an error message. On the brackground it uses printf.
   * @param message An string compatible with printf (may contain %s, %d, %f, ...)
   * @param ... A variable list of arguments for printf
   */
  void (*error)(char* message, ...);

  /**
   * @brief Print awarning message. On the brackground it uses printf.
   * @param message An string compatible with printf (may contain %s, %d, %f, ...)
   * @param ... A variable list of arguments for printf
   */
  void (*warning)(char* message, ...);

  /**
   * @brief Print an error message. On the brackground it uses printf.
   * @param message An string compatible with printf (may contain %s, %d, %f, ...)
   * @param ... A variable list of arguments for printf
   */
  void (*info)(char* message, ...);
} iDebug;
