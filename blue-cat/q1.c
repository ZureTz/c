#include <stdio.h>

int main() {
  float product = 1, sum = 1;
  for (int n = 1; n <= 20; n++) {
    product = product * n;
    sum = sum + product;
  }
  printf("1! + 2! + 3! + ... + n! = %e\n", sum);
}