#include <stdio.h>

// Binary Search Tree traversal algorithm with arbitrary function
void* func(int (*callback)(int, void*), void** arg2, int arg3) {
    if (arg2 == NULL)
        return NULL;

    while (1) {

        int callback_ret = callback(arg3, *arg2);

        if (callback_ret == 0) {

            return arg2;
            
        } else if (callback_ret >= 0) {

            arg2 = arg2[6];
            if (arg2 == NULL)
                return NULL;

        } else {

            arg2 = arg2[4];
            if (arg2 == NULL)
                return NULL;
            
        }
    }
}

int main(int argc, char** argv) {
    return 0;
}