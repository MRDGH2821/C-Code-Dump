/**
 * @file void_pointer_float.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief Void pointer type casted to float
 * @version 0.1
 * @date 2024-05-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
int main() {
  int i = 10;
  void *p = &i;
  printf("%f\n", *(float *)p);
  return 0;
}
