#include <stdio.h>

int func(int(*)() callback, void* arg2, void* arg3) {
    int func_ret = (*callback)(arg3, *arg2)
    if (func_ret == 0)
        return arg2;
    
    
}

int main(int argc, char** argv) {
    return 0;
}