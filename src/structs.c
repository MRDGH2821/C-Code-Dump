/**
 * @file structs.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief Display details of employees using structures.
 * @version 0.1
 * @date 2024-05-12
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
struct employee {
  int id, salary;
  char name[40], dept[40];
};

int main() {
  struct employee e[3];

  for (int i = 0; i < 3; i++) {
    printf("Enter details of Employee %d", i + 1);
    printf("Name:");
    fgets(e[i].name, sizeof(e[i].name), stdin);
    printf("Department:");
    fgets(e[i].dept, sizeof(e[i].dept), stdin);
    printf("ID:");
    int_scan(&e[i].id);
    printf("Salary:");
    int_scan(&e[i].salary);
  }

  int choice;
  printf("Whose details to find (1,2,3,4)?");
  int_scan(&choice);
  choice = choice - 1;
  printf("Name: %s\n", e[choice].name);
  printf("Department: %s\n", e[choice].dept);
  printf("ID: %d\n", e[choice].id);
  printf("Salary: %d\n", e[choice].salary);
}
