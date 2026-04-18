#include "unity.h"
#include "crng/crng.h"
#include <stdint.h>

void setUp(void) {}
void tearDown(void) {}

void test_crng_fill_returns_success(void) {
    uint8_t buf[16];
    int result = crng_fill(buf, sizeof(buf));
    TEST_ASSERT_EQUAL_INT(0, result);
}

void test_crng_fill_not_all_zero(void) {
    uint8_t buf[32];
    crng_fill(buf, sizeof(buf));

    int all_zero = 1;
    for (int i = 0; i < 32; i++) {
        if (buf[i] != 0) {
            all_zero = 0;
            break;
        }
    }

    TEST_ASSERT_FALSE(all_zero);
}

void test_crng_u64_changes(void) {
    uint64_t a = crng_u64();
    uint64_t b = crng_u64();

    
    TEST_ASSERT_NOT_EQUAL(a, b);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_crng_fill_returns_success);
    RUN_TEST(test_crng_fill_not_all_zero);
    RUN_TEST(test_crng_u64_changes);

    return UNITY_END();
}