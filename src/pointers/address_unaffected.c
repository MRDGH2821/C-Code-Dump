/**
 * @file address_unaffected.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief Demonstrates that the address of a variable remains unaffected even if the variable is modified
 * @version 0.1
 * @date 2024-04-30
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
int x = 0;
int main() {
  int *ptr = &x;
  printf("%p\n", ptr);
  x++;
  printf("%p\n", ptr);
  return 0;
}
