/**
 * @file pointer_to_character_pointer.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief Pointer to character pointer
 * @version 0.1
 * @date 2024-05-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
int main() {
  char *s = "hello";
  char *p = s;
  printf("%c\t%c\n", p[1], s[1]);
  return 0;
}
