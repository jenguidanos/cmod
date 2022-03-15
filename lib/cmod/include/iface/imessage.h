#pragma once

#include "cmod-platform.h"

/**
 * @brief Data model for messages
 *
 * This file only contains the declaration. Definition should be implemented
 * in the module implementation.
 */
typedef struct iMessageData iMessageData;

/**
 * @brief Data type for message properties
 *
 * A property name identifies a sensor value
 */
typedef uint8_t iMessageProperty;

/**
 * @brief Declare the main iMessage type
 *
 * It contains the data model and the interface setter/getter.
 */
typedef struct iMessage {
  iMessageData *data;
  int (*init)();
  int (*set)(iMessageProperty prop, ...);
  int (*setData)(iMessageData *data);
  iMessageData *(*get)();
} iMessage;
