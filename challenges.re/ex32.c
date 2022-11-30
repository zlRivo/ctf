#include <stdio.h>

// A and B point to the same string
char* f(char* haystack, char* needle) {

    char* old_a = haystack;
    char* old_b = needle;

    if (*needle == '\0') {
        return haystack;
    }

    char chr = *haystack;
    if (chr == '\0') {
        return NULL;
    }

    int offset = haystack - needle;

    char* ptr = old_b;

    do {
        if (chr != '\0') {
            do {
                char chr2 = *ptr;
                if (chr2 == '\0')
                    return old_a;
                
                if (ptr[offset] != chr2)
                    break;
                
                ptr++;
            } while (ptr[offset] != '\0');
        }

        if (*ptr == '\0')
            return old_a;

        chr = old_a[1];
        old_a++;
        offset++;

    } while (chr != '\0');

    return NULL;
}

int main(int argc, char* argv[]) {
    return 0;
}