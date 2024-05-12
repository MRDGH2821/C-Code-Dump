/**
 * @file quadratic_roots_finder.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief Finds quadratic roots of a quadratic equation
 * @version 0.1
 * @date 2024-05-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void float_scan(float *number) {
  char s[10] = {};
  fgets(s, sizeof(number), stdin);
  *number = strtol(s, NULL, 10);
}

int main() {
  float a, b, c, disc, root1, root2, root3;
  printf("Enter the value of a,b,c (in the equation ax^2+bx+c):\n");
  float_scan(&a);
  float_scan(&b);
  float_scan(&c);
  disc = pow(b, 2) - 4 * a * c;

  if (disc > 0) {
    root1 = (-b + sqrt(disc)) / (2 * a);
    root2 = (-b - sqrt(disc)) / (2 * a);

  } else if (disc == 0) {
    root1 = (-b / 2 * a);
    root2 = root1;

  } else {
    root1 = -b / (2 * a);
    root2 = -b / (2 * a);
    root3 = sqrt(-disc) / (2 * a);
  }

  if (disc >= 0) {
    printf("Root 1:%f \nRoot 2:%f", root1, root2);
  }

  if (disc < 0) {
    printf("Root 1: %f+%fi \nRoot 2: %f-%fi", root1, root3, root2, root3);
  }
}
