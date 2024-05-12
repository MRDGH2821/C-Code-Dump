/**
 * @file function_pointer.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief Function returning a pointer
 * @version 0.1
 * @date 2024-05-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
int *f();
int main() {
  int *p = f();
  printf("%d\n", *p);
}

int *f() {
  int j = 10;
  int *k = &j;
  return k;
}
