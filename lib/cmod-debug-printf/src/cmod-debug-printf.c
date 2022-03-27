#include "cmod-debug-printf.h"

#include "cmod.h"

int cmodDebugPrintfInit();
void cmodDebugPrintfError(char* message, ...);
void cmodDebugPrintfWarn(char* message, ...);
void cmodDebugPrintfInfo(char* message, ...);
void cmodPrintf(iDebugLevelType level, char* message, va_list);

static const char CMOD_DP_ERROR_TAG[] = "ERROR";
static const char CMOD_DP_WARN_TAG[] = "WARN";
static const char CMOD_DP_INFO_TAG[] = "INFO";
static const char CMOD_DP_VPRINTF_TAG[] = "[%s] ";

iDebug cmodDebugPrintf = {
    .init = cmodDebugPrintfInit,
    .error = cmodDebugPrintfError,
    .warning = cmodDebugPrintfWarn,
    .info = cmodDebugPrintfInfo,
};

void cmodDebugPrintfError(char* message, ...) {
  va_list args;
  va_start(args, message);
  cmodPrintf(CMOD_ERROR, message, args);
  va_end(args);
}

void cmodDebugPrintfWarn(char* message, ...) {
  va_list args;
  va_start(args, message);
  cmodPrintf(CMOD_WARNING, message, args);
  va_end(args);
}

void cmodDebugPrintfInfo(char* message, ...) {
  va_list args;
  va_start(args, message);
  cmodPrintf(CMOD_INFO, message, args);
  va_end(args);
}

void cmodPrintf(iDebugLevelType level, char* message, va_list args) {
  printf(CMOD_DP_VPRINTF_TAG, level == CMOD_ERROR     ? CMOD_DP_ERROR_TAG
                              : level == CMOD_WARNING ? CMOD_DP_WARN_TAG
                                                      : CMOD_DP_INFO_TAG);
  vprintf(message, args);
  printf("\n");
}

int cmodDebugPrintfInit() {
  cmod.log->info("[INIT] DEBUG printf enabled.");
  return 0;
}
