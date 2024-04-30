// name, id, dept, salary. o/p - whose details you want. - 4 names as options.
// display details.

#include <stdio.h>
struct employee {
  int id, salary;
  char name[40], dept[40];
};

int main() {
  struct employee e[3];

  for (int i = 0; i < 3; i++) {
    printf("Enter details of Employee %d", i + 1);
    printf("Name:");
    scanf("%s", e[i].name);
    printf("Department:");
    scanf("%s", e[i].dept);
    printf("ID:");
    scanf("%d", &e[i].id);
    printf("Salary:");
    scanf("%d", &e[i].salary);
  };

  int c;

  printf("Whose details to find (1,2,3,4)?");

  scanf("%d", &c);

  c = c - 1;

  printf("Name: %s\n", e[c].name);

  printf("Department: %s\n", e[c].dept);

  printf("ID: %d\n", e[c].id);

  printf("Salary: %d\n", e[c].salary);
}
