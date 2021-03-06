// Tests that the Array Subscript Operator works with dynamic checks
//
// The following lines are for the clang automated test suite
//
// This builds the file `read-subscript-check.c` at optimisation level O3, outputting an
// executable at %t. We then run this with the same arguments as we run the unoptimised
// binary with, and use FileCheck to ensure the output is what we expected, as specified
// in `read-subscript-check.c`. This is run as a seperate test so we know if optimisation is
// breaking our dynamic checks.
//
// RUN: %clang -fcheckedc-extension %S/read-subscript-check.c -o %t -Werror -O3
// RUN: %t 0 0 0 0  0 0   0 0 0  | FileCheck %S/read-subscript-check.c
// RUN: %t 1 2 4 4  1 2   1 1 1  | FileCheck %S/read-subscript-check.c
// RUN: %t 2 4 8 8  2 1   2 2 2  | FileCheck %S/read-subscript-check.c
// RUN: %t 2 4 8 8  0 4   0 3 2  | FileCheck %S/read-subscript-check.c
// RUN: %t 2 4 8 8  1 3   0 1 5  | FileCheck %S/read-subscript-check.c
// RUN: %t 2 4 8 8  2 -1  2 -1 2 | FileCheck %S/read-subscript-check.c
// RUN: %t 3        | FileCheck %S/read-subscript-check.c --check-prefix=CHECK-FAIL-1
// RUN: %t -1       | FileCheck %S/read-subscript-check.c --check-prefix=CHECK-FAIL-1
// RUN: %t 0 5      | FileCheck %S/read-subscript-check.c --check-prefix=CHECK-FAIL-1
// RUN: %t 0 -1     | FileCheck %S/read-subscript-check.c --check-prefix=CHECK-FAIL-1
// RUN: %t 0 0 9    | FileCheck %S/read-subscript-check.c --check-prefix=CHECK-FAIL-1
// RUN: %t 0 0 -1   | FileCheck %S/read-subscript-check.c --check-prefix=CHECK-FAIL-1
// RUN: %t 0 0 0 9  | FileCheck %S/read-subscript-check.c --check-prefix=CHECK-FAIL-1
// RUN: %t 0 0 0 -1 | FileCheck %S/read-subscript-check.c --check-prefix=CHECK-FAIL-1
// RUN: %t 0 0 0 0  3 0   | FileCheck %S/read-subscript-check.c --check-prefix=CHECK-FAIL-2
// RUN: %t 0 0 0 0  2 3   | FileCheck %S/read-subscript-check.c --check-prefix=CHECK-FAIL-2
// RUN: %t 0 0 0 0  0 9   | FileCheck %S/read-subscript-check.c --check-prefix=CHECK-FAIL-2
// RUN: %t 0 0 0 0  -1 -1 | FileCheck %S/read-subscript-check.c --check-prefix=CHECK-FAIL-2
// RUN: %t 0 0 0 0  0 0  3 0 0    | FileCheck %S/read-subscript-check.c --check-prefix=CHECK-FAIL-3
// RUN: %t 0 0 0 0  0 0  2 9 0    | FileCheck %S/read-subscript-check.c --check-prefix=CHECK-FAIL-3
// RUN: %t 0 0 0 0  0 0  2 2 3    | FileCheck %S/read-subscript-check.c --check-prefix=CHECK-FAIL-3
// RUN: %t 0 0 0 0  0 0  0 0 27   | FileCheck %S/read-subscript-check.c --check-prefix=CHECK-FAIL-3
// RUN: %t 0 0 0 0  0 0  -1 -1 -1 | FileCheck %S/read-subscript-check.c --check-prefix=CHECK-FAIL-3

#include <stdlib.h>

int main(void) {
  // Don't run this file
  return EXIT_FAILURE;
}
