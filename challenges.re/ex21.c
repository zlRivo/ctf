#include <stdio.h>
#include <string.h>

int f1(char* str, char* str2) {
    int len = strlen(str);
    int res = len - strlen(str2);

    return strcmp(&str[res], str2) == 0;
}

// Worldy World

int main(int argc, char** argv) {
    return 0;
}
