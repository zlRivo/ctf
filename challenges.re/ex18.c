#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int decode_uuid(char* str, u_int64_t* a, u_int64_t* b, u_int64_t* c, u_int64_t* d, u_int64_t* e) {
    int len = strlen(str);
    if (len != 36) {
        return -1;
    }

    char* ptr = str;
    for (int i = 0; i < 36; i++) {

        if (i == 8 || i == 13 || i == 18  || i == 23) {
            if (*ptr != '-') {
                return -1;
            }
        } else {
            if (!isxdigit(*ptr)) {
                return -1;
            }
        }

        ptr++;
    }

    // Input:
    // FFFFFFFF-FFFF-FFFF-FFFF-FFFFFFFFFFFF
    *a = strtol(str, NULL, 16);
    *b = strtol(&str[8], NULL, 16);
    *c = strtol(&str[13], NULL, 16);
    *d = strtol(&str[18], NULL, 16);
    *e = strtoll(&str[24], NULL, 16);

}

int main(int argc, char** argv) {
    return 0;
}