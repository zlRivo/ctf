#include <stdio.h>

// a: Pointer to array
// b: Index in the array
int f2(int *a, int b, int c) {

    int i = 0;
    int *addr = &a[b];
    int val = c + 1;
    int val2 = *addr;

    while (1) {

        int xor = addr[i + 1];
        b++;

        if (xor <= val2 && xor <= c) {
            i++;
            continue;
        }

        int *ptr = &a[val - 1];
        int *ptr_save = ptr;

        do {
            ptr--;
            val--;
        } while (ptr[1] > val2);

        if (b >= val) {
            *addr = *ptr_save = (ptr[1] ^ *addr) ^ *ptr_save;
            break;
        }

        addr[i + 1] = *ptr_save = (ptr[1] ^ xor) ^ *ptr_save;
        i++;
    }

    return val;
}

void f1(int* a, int b, int c) {

    while (b >= c) {

        int ret = f2(a, b, c);

        b = ret + 1;
        f1(a, b, ret - 1);
    }

}

int main(int argc, char **argv) {
    return 0;
}