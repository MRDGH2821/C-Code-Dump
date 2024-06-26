/**
 * @file pointer_address.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief Prints the address of a variable using a pointer
 * @version 0.1
 * @date 2024-05-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
int main() {
  int x = 0;
  int *ptr = &x;
  printf("%p\n", ptr);
  x++;
  printf("%p\n", ptr);
  return 0;
}
