/**
 * @file printing_pointer.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief
 * @version 0.1
 * @date 2024-04-30
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
int main() {
  int x = 0;
  int *ptr = &x;
  printf("%d\n", *ptr);
  return 0;
}
