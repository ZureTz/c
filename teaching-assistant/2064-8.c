// #  7909 AC329 - B - Next

// ## Problem Statement

// You are given $N$ integers $A_1, A_2, \ldots, A_N$. Find the largest among
// those integers that are not the largest.

// The constraints of this problem guarantee that the answer exists.

// ## Constraints

// -   $2 \leq N \leq 100$
// -   $1 \leq A_i \leq 100$
// -   It is not the case that all $A_1, A_2, \ldots, A_N$ are equal.
// -   All input values are integers.

// ## Input

// The input is given from Standard Input in the following format:

// $N$
// $A_1$ $A_2$ $\ldots$ $A_N$

// ## Output

// Print the answer.

// ## Sample Input 1

// ```
// 5
// 2 1 3 3 2
// ```

// ### Sample Output 1

// ```
// 2
// ```

// The largest integer among $2,1,3,3,2$ is $3$.

// The integers that are not $3$ among $2,1,3,3,2$ are $2,1,2$, among which the
// largest is $2$.

// ### Sample Input 2

// ```
// 4
// 4 3 2 1
// ```

// ### Sample Output 2

// ```
// 3
// ```

// ### Sample Input 3

// ```
// 8
// 22 22 18 16 22 18 18 22
// ```

// ### Sample Output 3

// ```
// 18
// ```

#include <stdio.h>

int main(int argc, char const *argv[]) {
  // Input N and A
  int nArraySize;
  scanf("%d", &nArraySize);

  // Create array based on size
  int array[nArraySize];
  // Then, input numbers
  for (int i = 0; i < nArraySize; i++) {
    scanf("%d", &array[i]);
  }

  // Find the largest and second largest numbers
  int largestNumber = array[0];
  // Since the problem constraint A_i is at least 1, -1 can be used to indicate
  // the initial state of not found
  int secondLargestNumber = -1;

  // First, find the largest number
  for (int i = 1; i < nArraySize; i++) {
    if (array[i] > largestNumber) {
      largestNumber = array[i];
    }
  }

  // Then, find the second largest number (the largest number that is not equal
  // to the largest number)
  for (int i = 0; i < nArraySize; i++) {
    if (array[i] < largestNumber && array[i] > secondLargestNumber) {
      secondLargestNumber = array[i];
    }
  }

  // Output the second largest number
  printf("%d\n", secondLargestNumber);

  return 0;
}