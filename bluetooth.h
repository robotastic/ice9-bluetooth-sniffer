/*
 * Copyright (c) 2022 ICE9 Consulting LLC
 */

#ifndef __BLUETOOTH_H__
#define __BLUETOOTH_H__

#include <stdint.h>
#include <time.h>

void bluetooth_detect(uint8_t *bits, unsigned len, unsigned freq, float rssi, struct timespec timestamp, uint32_t *lap_out, uint32_t *aa_out);

typedef struct _ble_packet_t {
    uint32_t aa;
    unsigned freq; // frequency in MHz
    float rssi; // received signal strength indicator
    unsigned len; // length including AA + header + CRC
    struct timespec timestamp;
    uint8_t data[0]; // data starts at AA
} ble_packet_t;

#endif
