/**
 * @file binary_search.c
 * @author MRDGH2821
 * @brief Performs binary search on an array of numbers
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
  int SIZE;
  printf("Enter the quantity of numbers to put: ");
  int_scan(&SIZE);
  int arr[SIZE];

  printf("Enter numbers in ascending order:\n");
  for (int i = 0; i < SIZE; i++) {
    int_scan(&arr[i]);
  }

  int search;
  printf("Enter number to search: ");
  int_scan(&search);

  int low = 0, high = SIZE - 1, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] == search) {
      printf("Number found at position %d\n", mid + 1);
      return 0;
    } else if (arr[mid] < search) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
}
