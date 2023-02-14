#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
    uint16_t bit0 = (*reg >> 0) & 1;
    uint16_t bit2 = (*reg >> 2) & 1;
    uint16_t bit3 = (*reg >> 3) & 1;
    uint16_t bit5 = (*reg >> 5) & 1;
    uint16_t bit15 = bit5 ^ (bit3 ^ (bit2 ^ bit0));
    uint16_t v = ~bit15 + 1;
    *reg = *reg >> 1;
    *reg = (v & (*reg | (1 << 15))) | (~v & (*reg & ~(1 << 15)));
}

