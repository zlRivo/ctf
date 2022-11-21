#include <stdio.h>

int is_valid_hex(unsigned char c) {
    if ((c - '0') <= 9) {
        return 1;
    }

    if (((c & 0b11011111) - 65) > 5)
        return 0;

    return 1;
}

// Idk what this does
int f(char* a, char* b) {
    void* v = a - 1;
    char* cnt = b;
    while (a < v) {
        void* r13 = a + 1;
        void* r15 = r13;
        char var = *a;
        if (*a == '+') {
            var = ' ';
        } else if (*a == '%') {
            if (!is_valid_hex(b[1])) {
                return -1;
            }

            r13 = &b[3];

            if (!is_valid_hex(b[2])) {
                return -1;
            }

            int ret = sscanf(r15, "%2x", &var);
            if (ret == 0) {
                return -1;
            }
        }

        if (b != 0) {
            *cnt = var;
        }
        cnt++;
        a = r13;
    }

    return cnt - b;
}

int main(int argc, char** argv) {
    return 0;
}