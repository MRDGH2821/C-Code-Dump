/**
 * @file malloc_function_pointer.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief Function returning a pointer using malloc
 * @version 0.1
 * @date 2024-05-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
#include <stdlib.h>
int *f();

int main() {
  int *p = f();
  printf("%d\n", *p);
}

int *f() {
  int *j = (int *)malloc(sizeof(int));
  *j = 10;
  return j;
}
