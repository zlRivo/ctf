#include <stdio.h>

typedef unsigned char u8;
typedef int i32;
typedef long long u64;
typedef long long i64;

u8 f(u8 a) {
    return (u8)((((u64)a * (i64)0x202020202) & (i64)0x10884422010) % (i64)0x3ff);
}

int main(int argc, char** argv) {
    return 0;
}