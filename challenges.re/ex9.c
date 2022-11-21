#include <stdio.h>
#include <stdlib.h>

int yesno(char c) {
    if (c == 'Y' || c == 'y') {
        return 1;
    } else if (c == 'N' || c == 'n') {
        return 0;
    } else {
        puts("error!");
        exit(0);
    }
}

int main(int argc, char** argv) {
    return 0;
}