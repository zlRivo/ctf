#include <stdio.h>

typedef unsigned char byte_t;

// Zeros 256 bytes at the given pointer
void bzero256(byte_t* ptr) {
    for (int i = 0; i < 256; i++) {
        ptr[i] = 0;
    }
}

int main(int argc, char** argv) {
    return 0;
}