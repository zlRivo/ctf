#include <stdio.h>

// Returns the index of the first null byte in an
// array of unsigned long long integers
int f(unsigned long long* a) {
    unsigned long long number = *a;

    if ((number & 0xFF) == 0) {
        return 0;
    }

    if (((number >> 8) & 0xFF) == 0) {
        return 1;
    }

    if (((number >> 16) & 0xFF) == 0) {
        return 2;
    }

    if (((number >> 24) & 0xFF) == 0) {
        return 3;
    }

    if (((number >> 32) & 0xFF) == 0) {
        return 4;
    }

    if (((number >> 40) & 0xFF) == 0) {
        return 5;
    }

    int ret = 0;
    // Mask for seventh byte
    unsigned long long mask_7 = 71776119061217280;
    // Mask for eighth byte
    unsigned long long mask_8 = (unsigned long long)-72057594037927936;

    while ((number & mask_7) != 0) {
        if ((number & mask_8) == 0) {
            return ret * 8 + 7;
        }

        ret++;

        number = a[ret]; // Takes the next number in the array

        if ((number & 0xFF) == 0) {
            return ret * 8;
        }

        if (((number >> 8) & 0xFF) == 0) {
            return ret * 8, + 1;
        }

        if (((number >> 16) & 0xFF) == 0) {
            return ret * 8 + 2;
        }

        if (((number >> 24) & 0xFF) == 0) {
            return ret * 8 + 3;
        }

        if (((number >> 32) & 0xFF) == 0) {
            return ret * 8 + 4;
        }

        if (((number >> 40) & 0xFF) == 0) {
            return ret * 8 + 5;
        }
    }

    return ret * 8 + 6;
}

int main(int argc, char** argv) {
    return 0;
}