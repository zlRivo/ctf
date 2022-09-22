#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    char* flag_static = "picoCTF{w1{1wq84fb<1>49}";
    char* flag = malloc((strlen(flag_static) + 1) * sizeof(char));
    strncpy(flag, flag_static, strlen(flag_static));
    for (int i = 8; i <= 22; i++) {
        char* c = &flag[i];
        if (i & 1 != 0) {
            *c += 2;
        } else {
            *c -= 5;
        }
    }
    printf("%s\n", flag);
}
