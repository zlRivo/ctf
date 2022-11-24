#include <stdio.h>

// Im losing my mind
void f2(int* a, int b, int c, int* d) {
    int i = 0;
    int* addr = &a[b];
    int val = c + 1;
    int val2 = *addr;
    
    while (1) {
        int xor = addr[i + 1];
        b++;
        if (xor > val2 || xor > c) {
            break;
        }
        i++;
    }

    int* ptr = &a[val - 1];

    int* val3_save = ptr;
    ptr--;
    val--;
    if (val3_save[1] < val2) {
        continue;
    } else if (b >= val) {
        break;
    }
    
    int val4 = val3_save[1] ^ xor;
    addr[i + 1] = val4;

}

int main(int argc, char** argv) {
    return 0;
}