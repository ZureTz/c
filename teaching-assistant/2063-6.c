// 1006: AC269-A - Anyway Takahashi

// **Problem Statement**
// You are given integers $a, b, c,$ and $d$. Print two lines as follows.

// The first line should contain the result of calculating $(a+b)×(c−d)$ as an
// integer. The second line should contain ```Takahashi```, regardless of the
// input.

// **Constraints**
// - $−100≤a,b,c,d≤100$
// - $a, b, c,$ and $d$ are integers.

// Input
// $a$ $b$ $c$ $d$

// Output
// Print two lines according to the Problem Statement.

// Sample Input
// 100 100 100 -100

// Sample Output
// 40000
// Takahashi

// Include standard input/output library header file
// This gives us access to functions like scanf() and printf() that handle input and output operations
#include <stdio.h>

// The main function - the entry point of every C program
// When the program starts, execution begins at the first statement in main()
// int - specifies that the function returns an integer value
// argc - argument count (number of command-line arguments)
// argv - argument vector (array of strings containing the arguments)
// These parameters allow the program to receive input from the command line
int main(int argc, char const *argv[]) {
  // Declare four integer variables to store the input values
  // int - specifies that these variables will hold integer values
  // Variables must be declared before they can be used in C
  int a, b, c, d;
  
  // Read four integers from standard input (usually keyboard)
  // scanf() - function that reads formatted data from standard input
  // "%d %d %d %d" - format string that tells scanf() to read four integers separated by spaces
  // &a, &b, &c, &d - addresses of variables where scanf() should store the values
  // The & operator is used to get the memory address of a variable
  scanf("%d %d %d %d", &a, &b, &c, &d);

  // Calculate (a+b)*(c-d) and store the result in a constant variable
  // const - keyword that makes the variable's value unchangeable after initialization
  // Parentheses ensure the operations are performed in the correct order
  // First (a+b) and (c-d) are calculated, then their results are multiplied
  const int result = (a + b) * (c - d);
  
  // Print the calculated result followed by a newline character
  // printf() - function that outputs formatted data to standard output (usually screen)
  // "%d\n" - format string that tells printf() to output an integer followed by a newline
  // result - the variable whose value will be printed
  printf("%d\n", result);
  
  // Print the string "Takahashi" followed by a newline character
  // The \n character creates a new line after the text
  printf("Takahashi\n");

  // Return 0 to indicate the program executed successfully
  // By convention, returning 0 from main() indicates normal program termination
  // Any other value typically indicates an error occurred
  return 0;
}
