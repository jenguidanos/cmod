#pragma once

#include "platform.h"
/**
 * @brief Debug level types definition
 *
 * The order matters, first error, last log
 */
typedef enum { ERROR, WARNING, LOG } iDebugLevelType;

/**
 * @brief Interface for debug object
 *
 * This interface is used to print debug messages with log level. There are 3
 * log levels: log, error and warn.
 *
 * On some systems native's printf module is enough (used in cmod-debug-printf),
 * on others you may need to delegate on uart interfaces UART (could be
 * implemented in a module named cmod-debug-uart or similar).
 */
typedef struct iDebug {
  int level;

  int (*init)();
  int (*setLevel)(iDebugLevelType level);
  void (*log)(char* message, ...);
  void (*error)(char* message, ...);
  void (*warn)(char* message, ...);
} iDebug;
