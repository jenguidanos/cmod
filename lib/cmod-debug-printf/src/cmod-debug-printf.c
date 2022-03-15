#include "cmod-debug-printf.h"

#include "cmod.h"

int cmodDebugPrintfInit();
void cmodDebugPrintfError(char* message, ...);
void cmodDebugPrintfWarn(char* message, ...);
void cmodDebugPrintfInfo(char* message, ...);
void cmodPrintf(iDebugLevelType level, char* message, ...);

iDebug cmodDebugPrintf = {
    .init = cmodDebugPrintfInit,
    .error = cmodDebugPrintfError,
    .warning = cmodDebugPrintfWarn,
    .info = cmodDebugPrintfInfo,
};

void cmodDebugPrintfError(char* message, ...) {
  cmodPrintf(CMOD_ERROR, message);
}

void cmodDebugPrintfWarn(char* message, ...) {
  cmodPrintf(CMOD_WARNING, message);
}

void cmodDebugPrintfInfo(char* message, ...) { cmodPrintf(CMOD_INFO, message); }

void cmodPrintf(iDebugLevelType level, char* message, ...) {
  printf("[%s] ", level == CMOD_ERROR     ? "ERROR"
                  : level == CMOD_WARNING ? "WARNING"
                                          : "INFO");
  va_list args;
  va_start(args, message);
  vprintf(message, args);
  va_end(args);

  printf("\n");
}

int cmodDebugPrintfInit() { return 0; }
