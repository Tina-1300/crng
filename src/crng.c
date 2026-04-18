#include "../include/crng/crng.h"



#ifdef __linux__


#include <sys/random.h>
#include <unistd.h>

int crng_fill(void* buffer, size_t size) {
    if (!buffer || size == 0) return -1;

    size_t offset = 0;
    while (offset < size) {
        ssize_t ret = getrandom((char*)buffer + offset, size - offset, 0);
        if (ret < 0) return -1;
        offset += (size_t)ret;
    }

    return 0;
}

#endif

#ifdef __APPLE__

#include <stdlib.h>

int crng_fill(void* buffer, size_t size) {
    if (!buffer || size == 0) return -1;

    arc4random_buf(buffer, size);
    return 0;
}

#endif


#ifdef _WIN32

#include <windows.h>
#include <bcrypt.h>

#pragma comment(lib, "bcrypt.lib")

int crng_fill(void* buffer, size_t size) {
    if (!buffer || size == 0) return -1;

    NTSTATUS status = BCryptGenRandom(
        NULL,
        (PUCHAR)buffer,
        (ULONG)size,
        BCRYPT_USE_SYSTEM_PREFERRED_RNG
    );

    return (status == 0) ? 0 : -1;
}

#endif