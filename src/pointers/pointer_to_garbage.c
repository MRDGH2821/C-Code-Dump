/**
 * @file pointer_to_garbage.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief Pointer to Garbage value
 * @version 0.1
 * @date 2024-05-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
int main() {
  char *p = NULL;
  char *q;

  if (p) {
    printf("p has value!\n");

  } else {
    printf("p is null!\n");
  }

  if (q) {
    printf("q has value!\n");

  } else {
    printf("q is null!\n");
  }
}
