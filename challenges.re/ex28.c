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

// This function returns the median in an array
int f_main(void* arr, size_t count) {
    size_t size = count * 4;
    
    // Duplicates the integers array into a malloc'ed area
    // and sorts the array
    int* ptr = memcpy(malloc(size), arr, size);
    qsort(ptr, count, 4, compare);

    // Divide by two
    count = count >> 1;

    if (count & 1 == 0) { // b % 2 == 0
        int val = ptr[count] + ptr[count - 1];
        
        return (signed long long)((val >> 31) + val) >> 1; // Cast to ensure arithmetic shift
    }

    return ptr[count];
}

int main(int argc, char** argv) {
    return 0;
}