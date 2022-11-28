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
    void* ptr = malloc(size);
    return memcpy(ptr, addr, size);
} 

int f_main(void* a, )

int main(int argc, char** argv) {
    return 0;
}