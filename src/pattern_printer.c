/**
 * @file pattern_printer.c
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
  int i = 5;

  while (i >= 1) {
    int j = 1;
    while (j <= i) {
      printf("A");
      j++;
    }
    printf("\n");
    i--;
  }
  return 0;
}
