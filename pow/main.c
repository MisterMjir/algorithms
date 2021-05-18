#include <math.h>
#include <stdio.h>
#include <time.h>

/*
 * Pow
 *
 * Experimenting with power algorithms
 *
 * These are functions that raise a to the bth power fn(a, b)
 *
 * Only worrying about b being >= 0 and being an integer (for now)
 *
 * Structure:
 * - Functions
 * - Test boilerplate / registration
 * - Main
 */

/*
 * ========================================
 * Functions
 * ========================================
 */

/*
 * Recursive 2
 *
 * Square each power every time
 */
double pow_rec2(double a, double b)
{
  if (b == 0) {
    return 1;
  }
  else if (b == 1) {
    return a;
  }

  return a * a * pow_rec2(a, b - 2);
}

/*
 * Loop
 *
 * Loop the multiplication
 */
double pow_loop(double a, double b)
{
  double result = 1;

  while (b-- > 0) {
    result *= a;
  }

  return result;
}

/*
 * ========================================
 * Testing stuff
 * ========================================
 */

struct Function {
  double (*function)(double, double);
  const char *name;
};

/* Register the functions */
struct Function functions[] = {
  {pow,      "stdlib"},
  {pow_rec2, "Recursive 2"},
  {pow_loop, "Loop"},
};

/* Test Cases */
int tests[][2] = {
  {2, 2},
  {2, 3},
  {2, 64},
  {9, 10}
};

/*
 * ========================================
 * Main
 *
 * Test runner
 * ========================================
 */

int main(void)
{
  for (int i = 0; i < sizeof(tests) / (2 * sizeof(int)); ++i) {
    printf("%d to the %d\n\n", tests[i][0], tests[i][1]);
    for (int j = 0; j < sizeof(functions) / sizeof(struct Function); ++j) {
      clock_t start, end;
      double result;

      start = clock();
      result = functions[j].function(tests[i][0], tests[i][1]);
      end = clock();

      printf("Function: %s\n", functions[j].name);
      printf("Result: %f\n", result);
      printf("Time elapsed: %f\n\n", (double) (end - start) / CLOCKS_PER_SEC);
    }
    printf("====================\n");
  }

  return 0;
}
