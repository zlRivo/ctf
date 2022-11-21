#include <stdio.h>

void func(char* a, char* b) {
    char* ptr1 = a;
    char* ptr2 = b;
    while (1) {
        unsigned char temp = ptr1[0];
        *((unsigned short int*)ptr2) = (unsigned short int)temp;
        unsigned short word = *((unsigned short int*)ptr2);
        if (word == 0)
            break;
        
        ptr1++;
        ptr2 += 2;
    }
    return
}

int main(int argc, char** argv) {
    return 0;
}