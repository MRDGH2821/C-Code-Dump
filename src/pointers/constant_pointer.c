/**
 * @file constant_pointer.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief Demonstrates compile error when trying to modify a constant pointer
 * @version 0.1
 * @date 2024-05-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
int x = 0;
int main() {
  int *const ptr = &x;
  printf("%p\n", ptr);
  ptr++;
  printf("%p\n", ptr);
  return 0;
}
