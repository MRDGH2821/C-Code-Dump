#include <stdio.h>
int main() {
  char *s = "hello";
  char *p = s;
  printf("%c\t%c", p[1], s[1]);
  return 0;
}
