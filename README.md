# MLT (Mulato Layer Test)

A lightweight and simple testing framework for C/C++ programs with test suite support, timing measurements, and colorized output.

## Features

- Single header file integration
- Organized test suites with timing measurements
- Colorized output for better readability
- Support for multiple test types:
  - Unit tests with assertions
  - String comparison tests
  - Time execution measurements
  - Interactive tests
  - Input/Output comparison tests

## Quick Start

1. Add the header to your project:
```bash
mkdir tests && cd tests && git clone https://github.com/mulatinho/mlt
```

2. Include the header in your test file:
```c
#include "mlt.h"
```

3. Create your first test:
```c
#include "mlt.h"

int main(void) {
    mlt_start();

    mlt_suite_begin("Basic Tests");
    mlt_assert(2 + 2 == 4);
    mlt_streq("hello", "hello");
    mlt_suite_end();

    mlt_finish();
    return 0;
}
```

## Test Suite Features

- Organize related tests into suites
- Each suite tracks:
  - Number of tests run
  - Number of tests passed/failed
  - Execution time
- Maximum 16 test suites per session
- Suite names limited to 64 characters

## Available Macros

| Macro | Description |
|-------|-------------|
| `mlt_start()` | Initialize test session |
| `mlt_finish()` | Complete session and show results |
| `mlt_suite_begin(name)` | Start a new test suite |
| `mlt_suite_end()` | Complete current suite |
| `mlt_assert(test)` | Assert a condition is true |
| `mlt_streq(in, str)` | Assert strings are equal |
| `mlt_strneq(in, str)` | Assert strings are not equal |

## Output Format

Tests results are displayed with clear indicators:
- `[ OK]` - Test passed (green)
- `[ERR]` - Test failed (red)

Example output:
```
:. Starting test session at Mon Apr 15 10:30:45 2024

- Running suite: String Tests
  [ OK] PASS in 'test_strings()' line 10: strlen("test") == 4
  [ OK] PASS in 'test_strings()' line 11: strcmp(str1, str2) == 0

=== Test Session Summary ===
Total time elapsed: 0.001s

Suite: String Tests
  Tests: 2, Passed: 2, Failed: 0 (0.001s)

=== Final Results ===
PASSED: All tests completed successfully
Total Tests: 2, Passed: 2, Failed: 0
```

## Integration with Your Code

To prevent test code from being included in your main program, wrap your main function:

```c
#ifndef MLT_TESTING
int main(int argc, char **argv) {
    // Your main program code
    return 0;
}
#endif
```

## Compilation

Add to your Makefile:
```makefile
test:
    $(CC) -DMLT_TESTING=1 -Wall -I./tests/mlt -o test_program test_program.c
```

## Documentation

For detailed documentation, see the man page:
```bash
man ./doc/mlt.1
```

## License

Copyright © 2015 Alexandre Mulatinho <alex@mulatinho.net>

This is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.

## Contributing

If you like MLT, please follow and share. Bug reports and pull requests are welcome on GitHub at https://github.com/mulatinho/mlt.
