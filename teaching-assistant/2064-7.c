// # 7900 AC326 - B - 326-like Numbers

// ## Problem Statement

// A **326-like number** is a three-digit positive integer where the product of
// the hundreds and tens digits equals the ones digit.

// For example, $326,400,144$ are 326-like numbers, while $623,777,429$ are not.

// Given an integer $N$, find the smallest 326-like number greater than or equal
// to $N$. It always exists under the constraints.

// ## Constraints

// -   $100 \leq N \leq 919$
// -   $N$ is an integer.

// ## Input

// The input is given from Standard Input in the following format:

// $N$

// ## Output

// Print the answer.

// ### Sample Input 1

// ```
// 320
// ```

// ### Sample Output 1

// ```
// 326
// ```

// $320,321,322,323,324,325$ are not 326-like numbers, while $326$ is a 326-like
// number.Numbers from 320 to 325 aren't because the product of their hundreds
// and tens digits doesn't equal the ones digit. However, 326 is (3*2=6), so
// it's the output.

// ### Sample Input 2

// ```
// 144
// ```

// ### Sample Output 2

// ```
// 144
// ```

// $144$ is a 326-like number.144 is already a 326-like number because the
// product of its hundreds digit (1) and tens digit (4) equals the ones digit
// (4). Thus, the output is 144.

// ### Sample Input 3

// ```
// 516
// ```

// ### Sample Output 3

// ```
// 600
// ```

#include <stdio.h>

int main(int argc, char const *argv[])  {
  // Input number
  int n;
  scanf("%d", &n);

  // Output the smallest 326-like number greater than or equal to n
  for (int i = n; i <= 919; i++) {
    // Extract hundreds, tens, and ones digits
    const int hundreds = i / 100;
    const int tens = (i / 10) % 10;
    const int ones = i % 10;
    // This always exists under the constraints
    if (hundreds * tens == ones) {
      printf("%d\n", i);
      break;
    }
    // So that no other case are considered
    // ...
  }

  return 0;
}