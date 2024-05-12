/**
 * @file pointer_increment.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief Demonstrates incrementing a variable using a pointer
 * @version 0.1
 * @date 2024-05-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
int main() {
  int *ptr, a = 10;
  ptr = &a;
  *ptr += 1;
  printf("Pointer value: %d\nVariable value: %d\n", *ptr, a);
}
