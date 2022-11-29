#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// f1 is a comparaison function
int compare(int* a, int* b) {
    int res = *a - *b;
    if (res > 0) {
        return 1;
    } else if (res < 0) {
        return -1;
    }
    return 0;
}

void* my_memdup(size_t size, void* addr) {
    return memcpy(malloc(size), addr, size);
} 

int f_main(void* a, size_t b) {
    size_t size = b * 4;
    
    int* ptr = memcpy(malloc(size), a, size);
    qsort(ptr, b, 4, compare);

    b = b >> 1;

    if (b & 1 == 0) { // b % 2 == 0
        int val = ptr[b] + ptr[b - 1];
        
        return ((val >> 31) + val) >> 1;
    }

    return ptr[b];
}

int main(int argc, char** argv) {
    return 0;
}