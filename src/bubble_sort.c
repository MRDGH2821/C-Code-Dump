/**
 * @file bubble_sort.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief Sorts an array using bubble sort algorithm
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
  int a[10];
  int temp, i, j;

  printf("Enter 10 numbers:\n");
  for (i = 0; i < 10; i++) {
    int_scan(&a[i]);
  }

  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9 - i; j++) {
      if (a[j] > a[j + 1]) {
        temp = a[j + 1];
        a[j + 1] = a[j];
        a[j] = temp;
      }
    }
  }
  printf("Sorted array is:\n");
  for (i = 0; i < 10; i++) {
    printf("%d", a[i]);
    if (i < 9)
      printf(", ");
  }
  return 0;
}
