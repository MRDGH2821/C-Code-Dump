/**
 * @file index_finder.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief Finds index of given number, if present in the array
 * @version 0.1
 * @date 2024-04-30
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
#include <stdlib.h>

void int_scan(int *number) {
  char s[10] = {};
  fgets(s, sizeof(number), stdin);
  *number = strtol(s, NULL, 10);
}

int main() {
  int a[7] = {10, 20, 30, 40, 50, 60, 70};
  int i, index;

  printf("Enter the number to find its index:");
  int_scan(&index);

  int found = 0;
  for (i = 0; i <= 6; i++) {
    if (index == a[i]) {
      printf("index of %d is %d:", index, i);
      found = 1;
      break;
    } else {
      found = 0;
    }
  }
  if (found == 0) {
    printf("Number not found");
  }
}
