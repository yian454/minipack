#include <stdbool.h>
#include <inttypes.h>
#include <stdio.h>

//==============================================================================
//
// Minunit
//
//==============================================================================

#define mu_fail(MSG, ...) do {\
    fprintf(stderr, "%s:%d: " MSG "\n", __FILE__, __LINE__, ##__VA_ARGS__);\
    return 1;\
} while(0)

#define mu_assert(TEST) do {\
    if (!(TEST)) {\
        fprintf(stderr, "%s:%d: %s \n", __FILE__, __LINE__, #TEST);\
        return 1;\
    }\
} while (0)

#define mu_assert_with_msg(TEST, MSG, ...) do {\
    if (!(TEST)) {\
        fprintf(stderr, "%s:%d: %s " MSG "\n", __FILE__, __LINE__, #TEST, ##__VA_ARGS__);\
        return 1;\
    }\
} while (0)

#define mu_run_test(TEST) do {\
    fprintf(stderr, "%s\n", #TEST);\
    int rc = TEST();\
    tests_run++; \
    if (rc) {\
        fprintf(stderr, "\n  Test Failure: %s()\n", #TEST);\
        return rc;\
    }\
} while (0)

#define RUN_TESTS() int main() {\
   fprintf(stderr, "== %s ==\n", __FILE__);\
   int rc = all_tests();\
   fprintf(stderr, "\n");\
   return rc;\
}

int tests_run;



//==============================================================================
//
// Minunit
//
//==============================================================================

#define mu_assert_mem(PTR, COUNT, BYTES) do {\
    char *chars = BYTES; \
    uint8_t *bytes = (uint8_t*)chars; \
    int i; \
    for(i=0; i<COUNT; i++) { \
        if(((uint8_t*)PTR)[i] != bytes[i]) { \
            mu_fail("Memory does not match at byte: %d", i); \
        } \
    } \
} while(0)
