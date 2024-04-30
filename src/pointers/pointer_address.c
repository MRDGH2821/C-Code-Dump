#include <stdio.h>
int main() {
  int x = 0;
  int *ptr = &x;
  printf("%p\n", ptr);
  return 0;
}
