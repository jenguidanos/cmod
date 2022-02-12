#include "cmod-net-n27.h"

#include "cmod.h"
#include "modules.h"

/*
.########..########..####.##.....##....###....########.########
.##.....##.##.....##..##..##.....##...##.##......##....##......
.##.....##.##.....##..##..##.....##..##...##.....##....##......
.########..########...##..##.....##.##.....##....##....######..
.##........##...##....##...##...##..#########....##....##......
.##........##....##...##....##.##...##.....##....##....##......
.##........##.....##.####....###....##.....##....##....########
*/

// private methods

/*
.####.########....###.....######..########
..##..##.........##.##...##....##.##......
..##..##........##...##..##.......##......
..##..######...##.....##.##.......######..
..##..##.......#########.##.......##......
..##..##.......##.....##.##....##.##......
.####.##.......##.....##..######..########
*/

bool n27_setId(char* id);

bool n27_setPowerOn();
bool n27_setPowerOff();
bool n27_setStandby();
float n27_getBattery();

bool n27_enable();
bool n27_disable();
uint8_t n27_getCoverage();

bool n27_connect();
bool n27_disconnect();
bool n27_send(uint8_t* data);

iNet N27 = {
    .protocol = 0x01,
    .name = CMOD_NET_N27,
    .id = {'\0'},
    .setId = n27_setId,

    .enable = n27_enable,
    .disable = n27_disable,
    .getCoverage = n27_getCoverage,

    .connect = n27_connect,
    .disconnect = n27_disconnect,
    .send = n27_send,

    .setPowerOn = n27_setPowerOn,
    .setPowerOff = n27_setPowerOff,
    .setStandby = n27_setStandby,
    .getBattery = n27_getBattery,
};

/** */
bool n27_setId(char* id) { return false; }

/** */
bool n27_enable() { return false; }

/** */
bool n27_disable() { return false; }

/** */
uint8_t n27_getCoverage() { return 0; }

/** */
bool n27_connect() { return false; }

/** */
bool n27_disconnect() { return false; }

/** */
bool n27_send(uint8_t* data) { return false; }

/** */
bool n27_setStandby() { return false; }

/** */
bool n27_setPowerOn() { return false; }

/** */
bool n27_setPowerOff() { return false; }

/** */
float n27_getBattery() {
  printf(" YYEEEEE ");
  cmod.debug->log("Mola mazo!!");
  return 0;
}
