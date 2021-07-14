//
// Created by lyuqiang on 2021/7/14.
//

#ifndef HAPPY_C_BYTE_H
#define HAPPY_C_BYTE_H

#include "happyc.h"
#include <stdint.h>

uint16_t from_2_bytes(const byte_t *bytes, int len, int *error_code);
uint32_t from_4_bytes(const byte_t *bytes, int len, int *error_code);

byte_t *to_2_bytes(uint16_t i);
byte_t *to_4_bytes(uint32_t i);

#endif //HAPPY_C_BYTE_H
