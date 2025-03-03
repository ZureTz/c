// # 7894 AC324 - B - 3-smooth Numbers

// ## Problem Statement

// You are given a positive integer $N$. If there are integers $x$ and $y$ such
// that $N=2^x3^y$, print `Yes`; otherwise, print `No`.

// ## Constraints

// -   $1\leq N\leq10^{18}$
// -   $N$ is an integer.

// ## Input

// The input is given from Standard Input in the following format:

// $N$

// ## Output

// Print a single line containing `Yes` if there are integers $x$ and $y$ that
// satisfy the condition, and `No` otherwise.

// ### Sample Input

// ```
// 37748736
// ```

// ### Sample Output

// ```
// Yes
// ```

// ### Sample Input 1

// ```
// 324
// ```

// ### Sample Output 1

// ```
// Yes
// ```

// For $x=2,y=4$, we have $2^x3^y=2^23^4=4\times81=324$, so the condition is
// satisfied. Thus, you should print `Yes`.

// ### Sample Input 2

// ```
// 5
// ```

// ### Sample Output 2

// ```
// No
// ```

// There are no integers $x$ and $y$ such that $2^x3^y=5$. Thus, you should
// print `No`.

// ### Sample Input 3

// ```
// 32
// ```

// ### Sample Output 3

// ```
// Yes
// ```

// For $x=5,y=0$, we have $2^x3^y=32\times1=32$, so you should print `Yes`.

#include <stdio.h>

// Check if n is divisible by m
int canBeDividedBy(const unsigned long long n, const unsigned long long m) {
  return n % m == 0;
}

int main(int argc, char const *argv[]) {
  // Input number
  // Note that n can be as large as 10^18
  // So, use unsigned long long instead of int
  unsigned long long n;
  scanf("%llu", &n);

  // Check if n is a 3-smooth number
  // First, divide by 2 
  while (canBeDividedBy(n, 2)) {
    n /= 2;
  }

  // Then, divide by 3
  while (canBeDividedBy(n, 3)) {
    n /= 3;
  }

  // If n is 1, it is a 3-smooth number
  // Otherwise, it is not
  printf("%s\n", n == 1 ? "Yes" : "No");

  return 0;
}