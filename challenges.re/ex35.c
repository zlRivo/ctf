#include <stdio.h>

int f(int a, int b) {
    if (a == 0 || b == 0) {
        return a;
    }

    int val1 = a | b;
    int val2 = ~val1;
    int val3 = (~a) & a;
    // ...
}

int main(int argc, char** argv) {
    return 0;
}