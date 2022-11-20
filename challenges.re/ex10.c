#include <stdio.h>
#include <stdlib.h>
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 


unsigned char xand(unsigned char a, unsigned char b) {
    return ((a + b - 1) & (~b));
}

int main(int argc, char** argv) {
    unsigned char num = 45;
    for (unsigned char i = 0; i < 16; i++) {
        printf("i = %02u, num = %u hex: "BYTE_TO_BINARY_PATTERN", "BYTE_TO_BINARY_PATTERN" -> "BYTE_TO_BINARY_PATTERN"\n", i, num, BYTE_TO_BINARY(i), BYTE_TO_BINARY(num), BYTE_TO_BINARY(xand(i, num)));
    }
    return 0;
}
