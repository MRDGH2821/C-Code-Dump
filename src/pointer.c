/**
 * @file pointer.c
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
  int val;
  int *p;

  p = &val;
  printf("Enter a value: ");
  int_scan(p);
  printf("Entered value (using pointer): %d\n", *p);
}
