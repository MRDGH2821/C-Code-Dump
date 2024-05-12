/**
 * @file array_pointer_manipulation.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief Demonstrates manipulating array pointers
 * @version 0.1
 * @date 2024-05-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
void foo(int[]);

int main() {
  int ary[4] = {1, 2, 3, 4};
  foo(ary);
  printf("%d\n", ary[0]);
}

void foo(int *p) {
  int i = 10;
  p = &i;
  printf("%d\n", p[0]);
}
