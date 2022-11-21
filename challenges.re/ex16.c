#include <stdio.h>

int f(void* a, char* b) {
    if (b == NULL) {
        return NULL;
    }

    char* ptr = (long long unsigned int)b & -4; // Align pointer
}

int main(int argc, char** argv) {
    return 0;
}