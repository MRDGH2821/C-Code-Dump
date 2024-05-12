/**
 * @file structs.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief Perform CRUD & Search operations on ny Database.
 * @version 0.1
 * @date 2024-05-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void int_scan(int *number) {
  char s[10] = {};
  fgets(s, sizeof(number), stdin);
  *number = strtol(s, NULL, 10);
}

void strcopy(char *source, char *dest) {
  FILE *src_str = fmemopen(source, strlen(source), "r");
  fgets(dest, sizeof(dest), src_str);
}

int SIZE = 4;
struct db {
  char name[20];
  int ID;
};

int main() {
  struct db p[SIZE];
  int c, id, index;
  printf("DB Manager");
choice:
  printf("\n1. Add. \n2. Delete. \n3. Modify. \n4. Display. \n5. Search.\n6. "
         "Display All.\n(Any no.). Exit \nEnter choice:");
  int_scan(&c);

  switch (c) {
  case 1:
    printf("Enter data of 4 people:\n");

    for (int i = 0; i < SIZE; i++) {
      printf("Enter Name:");
      fgets(p[i].name, sizeof(p[i].name), stdin);
      printf("Enter ID:");
      int_scan(&p[i].ID);
    }

    goto choice;
    break;

  case 2:
    printf("Enter ID number to delete:\n");
    int_scan(&id);

    for (int i = 0; i < SIZE; i++) {
      if (p[i].ID == id) {
        index = i;

      } else {
        index = -2;
      }
    }

    if (index == -2) {
      printf("Data not found\n");

    } else {
      char d[] = {'0', '1'};
      strcopy(d, p[index].name);
      p[index].ID = 0;
      printf("Data deleted");
    }

    goto choice;
    break;

  case 3:
    printf("Enter ID number to modify:\n");
    int_scan(&index);
    printf("Enter Name:");
    fgets(p[index].name, sizeof(p[index].name), stdin);
    printf("Enter ID:");
    int_scan(&p[index].ID);
    goto choice;
    break;

  case 4:
    printf("Enter ID number to display:\n");
    int_scan(&id);

    for (int i = 0; i < SIZE; i++) {
      if (p[i].ID == id) {
        index = i;

      } else {
        index = -2;
      }
    }

    if (index == -2) {
      printf("Data not found\n");

    } else {
      printf("Name:%s\n", p[index].name);
      printf("ID:%d\n", p[index].ID);
    }

    goto choice;
    break;

  case 5:
    printf("Enter ID number to search:\n");
    int_scan(&id);

    for (int i = 0; i < SIZE; i++) {
      if (p[i].ID == id) {
        index = i;
        break;

      } else {
        index = -2;
      }
    }

    if (index == -2) {
      printf("Data not found\n");

    } else {
      printf("Data found\n");
    }

    goto choice;
    break;

  case 6:
    for (int i = 0; i < SIZE; i++) {
      printf("%d: %s , ", p[i].ID, p[i].name);
    }

    goto choice;
    break;

  default:
    exit(0);
  }
}
