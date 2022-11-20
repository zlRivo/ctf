#include <stdio.h>

void lower(char* str) {
    char c = *str;
    char* ptr = str;
    if (c == '\0')
        return;
    
    while (1) {
        if (c - 'A' < 25) {
            c += 0x20
            *ptr = c;
        }

        ptr++;
        if (*ptr == '\0')
            break;
    }
}

int main(int argc, char** argv) {
    return 0;
}
