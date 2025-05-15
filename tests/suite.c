#include <stdio.h>
#include <stdlib.h>
#include "../mlt.h"

/* Example string utilities for testing */
char* str_reverse(const char* str) {
    size_t len = strlen(str);
    char* rev = malloc(len + 1);
    for (size_t i = 0; i < len; i++) {
        rev[i] = str[len - 1 - i];
    }
    rev[len] = '\0';
    return rev;
}

/* Main test function */
int main(void) {
    mlt_start();

    /* String Operations Test Suite */
    mlt_suite_begin("String Operations");
    
    char* rev = str_reverse("hello");
    mlt_streq(rev, "olleh");
    free(rev);

    rev = str_reverse("world");
    mlt_streq(rev, "dlrow");
    free(rev);
    
    mlt_suite_end();

    /* Math Operations Test Suite */
    mlt_suite_begin("Basic Math");
    
    mlt_assert(2 + 2 == 4);
    mlt_assert(10 - 5 == 5);
    mlt_assert(3 * 4 == 12);
    mlt_assert(15 / 3 == 5);
    
    mlt_suite_end();

    mlt_finish();
    return 0;
} 
