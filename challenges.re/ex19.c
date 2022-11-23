#include <stdio.h>
#include <stdlib.h>

void* f2(char* a, int b, char* c, int d) {
    if (c == NULL) {
        return a;
    }

    int old_b = b;
    char* old_c = c;
    int old_d = d;

    int* ptr = malloc(d * 4 + 4); // d + 1 integer
    ptr[0] = -1;
    ptr[1] = 0;

    int i = 1;
    while (i != d) {
        int val = ptr[i] + 1;
        ptr[i + 1] = val; // Next element

        if (val > 0) {
            while (c[i] != c[val - 1]) {
                val = ptr[val - 1] + 1;
                ptr[i + 1] = val;

                if (val == 0)
                    break;
            }
        }

        i++;
    }

    char* rbx = a;
    char* ret = NULL;

    int j, k;
    i = j = k = 0;

    while (k < b) {
        if (i < 0 || rbx[k] == c[i]) {
            i++;
            j++;
            if (i == d) {
                j -= d;
                rbx += j;
                ret = rbx;
                break;
            }
            k = j;
        }
        i = ptr[k];
    }

    free(ptr);
    return rbx;
}

int main(int argc, char** argv) {
    return 0;
}