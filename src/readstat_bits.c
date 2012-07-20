//
//  dta_util.c
//  Wizard
//
//  Created by Evan Miller on 12/16/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <sys/types.h>
#include <stdint.h>

#include "readstat_bits.h"

char ones_to_twos_complement1(char num) {
    return num < 0 ? num+1 : num;
}

int16_t ones_to_twos_complement2(int16_t num) {
    return num < 0 ? num+1 : num;
}

int32_t ones_to_twos_complement4(int32_t num) {
    return num < 0 ? num+1 : num;
}

char twos_to_ones_complement1(char num) {
    return num < 0 ? num-1 : num;
}

int16_t twos_to_ones_complement2(int16_t num) {
    return num < 0 ? num-1 : num;
}

int32_t twos_to_ones_complement4(int32_t num) {
    return num < 0 ? num-1 : num;
}

uint16_t byteswap2(uint16_t num) {
    return ((num & 0xFF00) >> 8) | ((num & 0x00FF) << 8);
}

uint32_t byteswap4(uint32_t num) {
    num = ((num & 0xFFFF0000) >> 16) | ((num & 0x0000FFFF) << 16);
    return ((num & 0xFF00FF00) >> 8) | ((num & 0x00FF00FF) << 8);
}

uint64_t byteswap8(uint64_t num) {
    num = ((num & 0xFFFFFFFF00000000) >> 32) | ((num & 0x00000000FFFFFFFF) << 32);
    num = ((num & 0xFFFF0000FFFF0000) >> 16) | ((num & 0x0000FFFF0000FFFF) << 16);
    return ((num & 0xFF00FF00FF00FF00) >> 8) | ((num & 0x00FF00FF00FF00FF) << 8);
}

float byteswap_float(float num) {
    uint32_t answer = byteswap4(*(uint32_t *)&num);
    return *(float *)&answer;
}

double byteswap_double(double num) {
    uint64_t answer = byteswap8(*(uint64_t *)&num);
    return *(double *)&answer;
}