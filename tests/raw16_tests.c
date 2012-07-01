#include "minunit.h"
#include <minipack.h>

#include "memdump.h"

//==============================================================================
//
// Test Cases
//
//==============================================================================

int test_raw16_read_length() {
    mu_assert(minipack_raw16_read_length("\xDA\x00\x00") == 0);
    mu_assert(minipack_raw16_read_length("\xDA\x00\x05") == 5);
    mu_assert(minipack_raw16_read_length("\xDA\x01\x00") == 256);
    return 0;
}

int test_raw16_write() {
    uint8_t data[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    minipack_raw16_write(data, 0, NULL);
    mu_assert_mem(data, 3, "\xDA\x00\x00");

    minipack_raw16_write(data, 5, "abcde");
    mu_assert_mem(data, 8, "\xDA\x00\x05" "abcde");

    return 0;
}


//==============================================================================
//
// Setup
//
//==============================================================================

int all_tests() {
    mu_run_test(test_raw16_read_length);
    mu_run_test(test_raw16_write);
    return 0;
}

RUN_TESTS()