#ifndef CRNG_H
#define CRNG_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Returns 0 on success, non-zero on failure
int crng_fill(void* buffer, size_t size);

// Convenience helper
static inline uint64_t crng_u64() {
    uint64_t v;
    if (crng_fill(&v, sizeof(v)) != 0){
        return 0; 
    }
    return v;
}

#ifdef __cplusplus
}
#endif

#endif // CSECURE_RNG_H