#include "cmod-message-bin.h"

#include "iface/imessage.h"

int messageBinInit();
int messageBinSet(iMessageProperty prop, ...);
int messageBinSetData(iMessageData *data);
iMessageData *messageBinGet();

iMessageData messageData;

iMessage messageBin = {
    .init = messageBinInit,
    .set = messageBinSet,
    .setData = messageBinSetData,
    .get = messageBinGet,
};
