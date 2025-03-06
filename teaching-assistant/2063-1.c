// Program to calculate a+b
// 
// Input: Two integers a and b (0≤a,b≤10)
// Output: The result of a+b

// Sample Input: 1 2
// Sample Output: 3

// Include the standard input/output library
// stdio.h contains declarations for input/output functions like scanf and printf
#include <stdio.h>

// The main function is the entry point of the program, all C programs start execution here
// int indicates that the function returns an integer value
// argc represents the number of command line arguments, and argv contains all command line arguments
// These parameters are typically not used in simple programs but keeping them is standard practice in C
int main(int argc, char const *argv[]) {
  // Declare two integer variables a and b to store the input numbers
  int a, b;
  
  // Read two integers from standard input
  // scanf is an input function used to read data from keyboard
  // "%d %d" is the format string, indicating reading two integers separated by a space
  // &a, &b are addresses of variables, scanf needs addresses to store the read values
  scanf("%d %d", &a, &b);

  // Calculate a+b and output the result
  // printf is an output function used to print data to screen
  // "%d\n" is the format string, indicating printing an integer followed by a newline
  // a + b is the result of the expression to be printed
  printf("%d\n", a + b);

  // Return 0 indicates normal program termination
  // The return value is passed to the operating system, 0 typically means success
  return 0;
}
