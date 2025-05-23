# MLT - Minimalist Lightweight Testing for C

**mlt.h** is a simple, header-only C testing framework designed for expressive, colorful, and minimal test suites.  
It is ideal for small projects, CI scripts, and educational purposes.

## Features

- **Colorful output** for test results and summaries
- **Suite grouping** and timing with microsecond precision
- **Assertion macros** for integers and strings
- **String and array utilities**
- **Sorting helpers** for arrays and structs
- **Regex helpers** (wrappers for POSIX regex)
- **No external dependencies** except libc

## Quick Start

```c
#include "mlt.h"

int main(void) {
    mlt_start();

    mlt_suite_begin("math");
    mlt_assert(2 + 2 == 4);
    mlt_assert(6 / 2 == 3);
    mlt_suite_end();

    mlt_suite_begin("strings");
    char foo[] = "foo";
    char bar[] = "foobar";
    mlt_streq(bar, "foo");
    mlt_strupper(foo);
    mlt_assert(strcmp(foo, "FOO") == 0);
    mlt_suite_end();

    return mlt_finish();
}
```

## API Overview

## Available Macros and Utilities

| Macro / Function                | Description                                                      |
|---------------------------------|------------------------------------------------------------------|
| `mlt_start()`                   | Initialize test session and reset counters                       |
| `mlt_finish()`                  | Complete session, print summary, and return result               |
| `mlt_suite_begin(name)`         | Start a new test suite with the given name                       |
| `mlt_suite_end()`               | Complete the current suite and record its time                   |
| `mlt_assert(expr)`              | Assert that `expr` is true                                       |
| `mlt_streq(a, b)`               | Assert that strings `a` and `b` are equal (prefix match)         |
| `mlt_strneq(a, b)`              | Assert that strings `a` and `b` are not equal (prefix match)     |
| `mlt_strupper(str)`             | Convert `str` to uppercase in-place                              |
| `mlt_strlower(str)`             | Convert `str` to lowercase in-place                              |
| `mlt_strcontains(str, substr)`  | Returns 1 if `substr` is found in `str`, 0 otherwise             |
| `mlt_arr_len(arr)`              | Return the number of elements in array `arr`                     |
| `mlt_print_int_arr(arr, n)`     | Print an array of `int` of length `n`                            |
| `mlt_print_float_arr(arr, n)`   | Print an array of `float` of length `n`                          |
| `mlt_print_double_arr(arr, n)`  | Print an array of `double` of length `n`                         |
| `mlt_print_str_arr(arr, n)`     | Print an array of strings of length `n`                          |
| `mlt_define_comparision(type, name, expr)` | Define a comparison function for `qsort` for type/expr   |
| `mlt_define_compare_str(name)`  | Define a string comparison function for `qsort`                  |
| `mlt_define_compare_struct(type, field, name)` | Define a struct field comparison for `qsort`           |
| `mlt_regex_compile(pattern, regex_ptr)` | Compile a POSIX regex pattern                           |
| `mlt_regex_exec(regex_ptr, text)` | Execute a regex match on `text`                              |
| `mlt_regex_exec_match(regex_ptr, text, nmatch, pmatch)` | Regex match with submatches           |
| `mlt_regex_free(regex_ptr)`     | Free a compiled regex                                            |
| `mlt_debug(...)`                | Print debug output to stderr                                     |
| `mlt_time_init()`               | Initialize a timer for a test suite                              |
| `mlt_time_calc(end, ini)`       | Calculate elapsed time in seconds (as double)                    |

---

## Example: Using the Test Framework

See the [`tests/project_test`](./tests/project_test) folder for real-world usage.

### Folder Structure

```
tests/project_test/
├── Makefile
├── src/
│   └── (your source files)
└── tests/
    └── lib_test.c
```

### Example Test (`lib_test.c`)

```c
#include "config.h"
#include "mlt.h"

int main(void)
{
    mlt_start();

    mlt_suite_begin("lib test");
    mlt_assert(return_number_of_life() == 42);
    mlt_assert(sum_two_numbers(2, 3) == 5);
    mlt_suite_end();

    return mlt_finish();
}
```

### Example Makefile

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -I./include -I./../../ -g -ggdb
TEST_CFLAGS = -DMLT_TESTING=1

MAIN_SRCS = $(wildcard src/*.c)
TEST_SRCS = $(wildcard tests/*.c)
MAIN_OBJS = $(MAIN_SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)

all: main lib_test

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

main: $(MAIN_OBJS)
    $(CC) $^ -o src/$@

lib_test: $(MAIN_SRCS) $(TEST_OBJS)
    $(CC) $(CFLAGS) $(TEST_CFLAGS) $^ -o tests/$@

clean:
    rm -f $(MAIN_OBJS) $(TEST_OBJS) src/main tests/lib_test
```

---

## License

This project is licensed under the GNU Lesser General Public License v2.1 or later.  
See [LICENSE](LICENSE) for details.

---

## Author

Alexandre Mulatinho <alex@mulatinho.net>
