// # 7902 AC327 - A - ab

// ## Problem Statement

// You are given a string $S$ of length $N$ consisting of lowercase English
// letters. If there are any adjacent occurrences of `a` and `b` in $S$, print
// `Yes`; otherwise, print `No`. (The order of `a` and `b` does not matter.)

// ## Constraints

// -   $2 \leq N \leq 100$
// -   $S$ is a string of length $N$ consisting of lowercase English letters.

// ## Input

// The input is given from Standard Input in the following format:

// $N$
// $S$

// ## Output

// If there are any adjacent occurrences of `a` and `b` in $S$, print `Yes`;
// otherwise, print `No`.

// ### Sample Input 1

// ```
// 3
// abc
// ```

// ### Sample Output 1

// ```
// Yes
// ```

// The string `abc` has `a` as the first character and `b` as the second
// character, which are adjacent. Thus, print `Yes`.

// ### Sample Input 2

// ```
// 2
// ba
// ```

// ### Sample Output 2

// ```
// Yes
// ```

// The string `ba` has `a` as the second character and `b` as the first
// character, which are adjacent. (Note that the order of `a` and `b` does not
// matter.)

// ### Sample Input 3

// ```
// 7
// atcoder
// ```

// ### Sample Output 3

// ```
// No
// ```

#include <stdio.h>

int isAdjacent(const char a, const char b) {
  return (a == 'a' && b == 'b') || (a == 'b' && b == 'a');
}

int main(int argc, char const *argv[]) {
  // Input string length
  int nStringLength;
  scanf("%d", &nStringLength);

  // Create string based on length
  char sString[nStringLength + 1];
  // Input string
  scanf("%s", sString);

  // Check for adjacent occurrences of `a` and `b`
  for (int i = 0; i < nStringLength - 1; i++) {
    if (isAdjacent(sString[i], sString[i + 1])) {
      printf("Yes\n");
      return 0;
    }
  }
  // Otherwise print `No`
  printf("No\n");

  return 0;
}