#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Declare the f function.
double f(double x) {
  return x * x;
}

double trapezoidal_rule(double f(double), double a, double b, int n) {
  double h = (b - a) / n;
  double sum = 0.0;
  double x = a;
  for (int i = 0; i < n; i++) {
    sum += (f(x) + f(x + h)) / 2.0 * h;
    x += h;
  }

  return sum;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <N>\n", argv[0]);
    return 1; // Return an error code if no argument is provided.
  }

  int N = atoi(argv[1]); // convert input to an integer using atoi.
  printf("N = %i\n", N);

  // Compute the integral using the trapezoidal rule.
  double integral = trapezoidal_rule(f, -1.0, 1.0, N);

  // Print the integral to the console.
  printf("The integral is %f\n", integral);

  return 0; // Return 0 to indicate successful execution.
}
