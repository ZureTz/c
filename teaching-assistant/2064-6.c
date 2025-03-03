// # 7297 AC135-B - 0 or 1 Swap

// ## Problem Statement

// We have a sequence $p = {p_1, p_2, ..., p_N}$ which is a permutation of ${1,
// 2, ..., N}$.

// You can perform the following operation at most once: choose integers $i$ and
// $j$ $(1≤i<j≤N)$, and swap $p_i$ and $p_j$. Note that you can also choose not
// to perform it.

// Print ```YES``` if you can sort $p$ in ascending order in this way, and
// ```NO``` otherwise.

// ## Constraints

// - All values in input are integers.
// - $2≤N≤50$
// - $p$ is a permutation of ${1, 2, ..., N}$.

// ## Input

// $N$
// $p_1$ $p_2$ ... $p_N$

// ## Output

// Print ```YES``` if you can sort $p$ in ascending order in the way stated in
// the problem statement, and ```NO``` otherwise.

// ### Sample Input

// ```
// 7
// 1 2 3 4 5 6 7
// ```

// ### Sample Output

// ```
// YES
// ```

// ### Sample Input 1

// ```
// 5
// 5 2 3 4 1

// ```
// ### Sample Output 1

// ```
// YES
// ```
// You can sort $p$ in ascending order by swapping $p_1$ and $p_5$.

// ### Sample Input 2

// ```
// 5
// 2 4 3 5 1
// ```
// ### Sample Output 2

// ```
// NO
// ```
// In this case, swapping any two elements does not sort $p$ in ascending order.

#include <stdio.h>

int isArraySorted(int array[], int nArraySize) {
  for (int i = 0; i < nArraySize - 1; i++) {
    if (array[i] > array[i + 1]) {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char const *argv[]) {
  // Input size of array
  int nArraySize;
  scanf("%d", &nArraySize);

  // Create array based on size
  int array[nArraySize];
  // Then, input numbers
  for (int i = 0; i < nArraySize; i++) {
    scanf("%d", &array[i]);
  }

  // Check if the array is already sorted
  if (isArraySorted(array, nArraySize)) {
    printf("YES\n");
    return 0;
  }

  // Otherwise, check if swapping any two elements sorts the array
  for (int i = 0; i < nArraySize - 1; i++) {
    for (int j = i + 1; j < nArraySize; j++) {
      // Swap elements
      int temp = array[i];
      array[i] = array[j];
      array[j] = temp;

      // Check if the array is sorted after swapping
      if (isArraySorted(array, nArraySize)) {
        printf("YES\n");
        return 0;
      }

      // Swap back to restore original order
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }

  // If no swap can sort the array, print "NO"
  printf("NO\n");

  return 0;
}