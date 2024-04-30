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
