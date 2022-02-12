#pragma once

#include "iface/imessage.h"

struct iMessageData {
  int deviceId;
  float temp;
};

extern iMessageData messageData;
extern iMessage messageBin;
