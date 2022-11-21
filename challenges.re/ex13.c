#include <stdio.h>

// Writes each max value between two int array pointers into dst
void f(int* dst, int* a, int* b) {
    // Total number of bytes: 1024
    // Number of iterations when grouped as int: 1024 / 4 = 256
    for (int i = 0; i < 256; i++) {
        dst[i] = a[i] > b[i] ? a[i] : b[i];
    }
}

int main(int argc, char** argv) {
    return 0;
}