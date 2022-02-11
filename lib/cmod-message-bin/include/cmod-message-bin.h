#pragma once

#include "iface/imessage.h"
#include "platform.h"

struct iMessageData {
  int deviceId;
  float temp;
};

extern iMessageData messageData;
extern iMessage messageBin;
