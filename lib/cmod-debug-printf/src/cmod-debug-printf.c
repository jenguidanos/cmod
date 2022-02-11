#include "cmod-debug-printf.h"

#include "platform.h"

int cmodDebugPrintfInit();
void cmodDebugPrintfError(char* message, ...);
void cmodDebugPrintfWarn(char* message, ...);
void cmodDebugPrintfLog(char* message, ...);
void cmodPrintf(iDebugLevelType level, char* message, ...);

iDebug cmodDebugPrintf = {
    .init = cmodDebugPrintfInit,
    .error = cmodDebugPrintfError,
    .warn = cmodDebugPrintfWarn,
    .log = cmodDebugPrintfLog,
};

void cmodDebugPrintfError(char* message, ...) {}

void cmodDebugPrintfWarn(char* message, ...) {}

void cmodDebugPrintfLog(char* message, ...) {}

void cmodPrintf(iDebugLevelType level, char* message, ...) {
  printf("[%s] ", level == ERROR     ? "ERROR"
                  : level == WARNING ? "WARNING"
                                     : "LOG");
  va_list args;
  va_start(args, message);
  vprintf(message, args);
  va_end(args);

  printf("\n");
}
