#include <stdio.h>
void foo(int[]);

int main() {
  int ary[4] = {1, 2, 3, 4};
  foo(ary);
  printf("%d\n", ary[0]);
}

void foo(int *p) {
  int i = 10;
  p = &i;
  printf("%d\n", p[0]);
}
