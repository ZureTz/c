// # 6955: Fibonacci sequence

// ## Problem Statement

// Little garlic has recently learned the Fibonacci sequence.
// The Fibonacci sequence refers to a sequence where both the first and second
// numbers are 1, and the number of subsequent numbers is equal to the sum of
// the first two numbers. Given a positive integer k, what is the k-th number in
// the Fibonacci sequence.

// ## Input

// Enter a line containing a positive integer k. (1 ≤ k ≤ 46)

// ## Output

// Output a row containing a positive integer that represents the k-th number in
// the Fibonacci sequence.

// ### Sample Input

// ```
// 19
// ```

// ### Sample Output

// ```
// 4181
// ```

#include <stdio.h>

// Recursive Fibonacci sequence (basic solution but inefficient)
int fibonacciRecursive(const int n) {
  // Special case
  if (n == 1 || n == 2) {
    return 1;
  }

  // Recursive (Complexity: O(2^n))
  return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Fibonacci sequence using array (more efficient)
int fibonacci(const int n) {
  // Special case
  if (n == 1 || n == 2) {
    return 1;
  }

  // Dynamic programming (Complexity: O(n))
  int tempArray[n];
  tempArray[0] = 1;
  tempArray[1] = 1;
  for (int i = 2; i < n; i++) {
    tempArray[i] = tempArray[i - 1] + tempArray[i - 2];
  }
  return tempArray[n - 1];
}

int main(int argc, char const *argv[]) {
  // Input k-th number
  int k;
  scanf("%d", &k);

  // Output the corresponding number in fibonacci sequence
  printf("%d\n", fibonacci(k));
  // Or use the recursive function
  // printf("%d\n", fibonacciRecursive(k));

  return 0;
}