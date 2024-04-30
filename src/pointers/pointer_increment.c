#include <stdio.h>
int main() {
  int *ptr, a = 10;
  ptr = &a;
  *ptr += 1;
  printf("Pointer value: %d\nVariable value: %d\n", *ptr, a);
}
