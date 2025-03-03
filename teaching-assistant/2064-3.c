// # 7899 AC326 - A - 2UP3DOWN

// ## Problem Statement

// Takahashi is in a building with $100$ floors.

// He uses the stairs for moving up two floors or less or moving down three
// floors or less, and uses the elevator otherwise.

// Does he use the stairs to move from floor $X$ to floor $Y$?

// ## Constraints
// -   $1 \leq X,Y \leq 100$
// -   $X \neq Y$
// -   All input values are integers.

// ## Input

// The input is given from Standard Input in the following format:

// $X$ $Y$

// ## Output

// If Takahashi uses the stairs for the move, print `Yes`; if he uses the
// elevator, print `No`.

// ### Sample Input 1

// ```
// 1 4
// ```

// ### Sample Output 1

// ```
// No
// ```

// The move from floor $1$ to floor $4$ involves going up three floors, so
// Takahashi uses the elevator.

// ### Sample Input 2

// ```
// 99 96
// ```

// ### Sample Output 2

// ```
// Yes
// ```

// The move from floor $99$ to floor $96$ involves going down three floors, so
// Takahashi uses the stairs.

// ### Sample Input 3

// ```
// 100 1
// ```

// ### Sample Output 3

// ```
// No
// ```

// The move from floor $100$ to floor $1$ involves going down 99 floors, so
// Takahashi uses the elevator.

#include <stdio.h>

int main(int argc, char const *argv[]) {
  // Input two floors
  int x, y;
  scanf("%d %d", &x, &y);
  
  // Output whether Takahashi uses the stairs
  // Case when moving up
  if (x < y) {
    printf("%s\n", (y - x <= 2) ? "Yes" : "No");
    return 0;
  }
  // Case when moving down
  printf("%s\n", (x - y <= 3) ? "Yes" : "No");

  return 0;
}