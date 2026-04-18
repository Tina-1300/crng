#include <stdio.h>
#include <stdint.h>
#include <crng.h>

void print_hex(const uint8_t* data, size_t len){
    for (size_t i = 0; i < len; i++){
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main(void){
    // 1 example
    unsigned int buff;
    if (crng_fill(&buff, sizeof(buff)) == 0){
        printf("rng value 1 : %u\n", buff);
    }

    // 2 example
    uint64_t buffer = crng_u64();
    printf("rng value 2 : %llu\n", (unsigned long long)buffer);

    // 3 example
    printf("rng value 3 : %llu\n", (unsigned long long)crng_u64());

    // 4 example (salt)
    uint8_t salt[16];
    if (crng_fill(salt, sizeof(salt)) == 0){
        printf("salt : ");
        print_hex(salt, sizeof(salt));
    }

    return 0;
}