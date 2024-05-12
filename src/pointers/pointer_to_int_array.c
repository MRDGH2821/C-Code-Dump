/**
 * @file pointer_to_int_array.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief Pointer to integer array
 * @version 0.1
 * @date 2024-05-12
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
void main() {
  int a[3] = {1, 2, 3};
  int *p = a;
  printf("%p\t%p", p, a);
}
