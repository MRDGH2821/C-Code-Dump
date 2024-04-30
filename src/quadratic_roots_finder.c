#include <math.h>
#include <stdio.h>
int main() {
  float a, b, c, disc, root1, root2, root3;
  printf("Enter the value of a,b,c (in the equation ax^2+bx+c):\n");
  scanf("%f %f %f", &a, &b, &c);
  disc = pow(b, 2) - 4 * a * c;
  
  if (disc > 0) {
    root1 = (-b + sqrt(disc)) / (2 * a);
    root2 = (-b - sqrt(disc)) / (2 * a);
    
  } else if (disc == 0) {
    root1 = (-b / 2 * a);
    root2 = root1;
    
  } else if (disc < 0) {
    root1 = -b / (2 * a);
    root2 = -b / (2 * a);
    root3 = sqrt(-disc) / (2 * a);
  }
  
  if (disc >= 0) {
    printf("Root 1:%f \nRoot 2:%f", root1, root2);
  }
  
  if (disc < 0) {
    printf("Root 1: %f+%fi \nRoot 2: %f-%fi", root1, root3, root2, root3);
  }
}
