#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    // Read the seed
    FILE* f = fopen("flag.enc", "rb");
    if (f == NULL) {
        printf("flag.enc does not exist");
        exit(1);
    }

    unsigned length;
    unsigned char seed_buf[4];
    unsigned char current_char = '\0'; // Unsigned char for shifting
    unsigned seed = 0;

    // Get the file length
    fseek(f, 0, SEEK_END);
    length = ftell(f);
    printf("%d\n", length);
    char* char_buf = malloc((sizeof(char) + 1) * length);
    fseek(f, 0, SEEK_SET);

    // Read and set the seed from the file
    fread(seed_buf, 4, 1, f);
    seed = seed_buf[3] << 24 | seed_buf[2] << 16 | seed_buf[1] << 8 | seed_buf[0];
    srand(seed);

    for (int i = 0; i < length; i++) {
        // Read one byte from the file
        fread(&current_char, 1, 1, f);
        printf("%d\n", i);

        // Get both random values
        int rand_num = rand();
        unsigned rand_shift = rand() & 7;

        char_buf[i] = current_char << 8 - rand_shift | current_char >> rand_shift;
        char_buf[i] ^= (unsigned char)rand_num;
    }

    // Null terminator
    char_buf[length] = '\0';
    printf("%s\n", char_buf);

    fclose(f);
    free(char_buf);
    return 0;
}