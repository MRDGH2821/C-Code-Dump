/**
 * @file linear_search.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief
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
  int num, i, flag = 0;

  printf("Enter 5 numbers:\n");
  for (i = 0; i < 5; i++) {
    int_scan(&a[i]);
  }
  printf("Enter number to be searched");
  int_scan(&num);
  for (i = 0; i < 5; i++) {
    if (num == a[i]) {
      flag = 1;
      break;
    }
  }
  if (flag == 1) {
    printf("Number found at %d", i + 1);
  } else {
    printf("Number not found");
  }
}
