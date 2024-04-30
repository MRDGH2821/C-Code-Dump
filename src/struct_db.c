// WAP to perform following operations on any Database: 1. Add. 2. Delete. 3.
// Modify. 4. Display. 5. Search.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int size = 4;
struct db {
  char name[20];
  int ID;
};

int main() {
  struct db p[size];
  int c, id, index;
  printf("DB Manager");
choice:
  printf("\n1. Add. \n2. Delete. \n3. Modify. \n4. Display. \n5. Search.\n6. "
         "Display All.\n(Any no.). Exit \nEnter choice:");
  scanf("%d", &c);

  switch (c) {
  case 1:
    printf("Enter data of 4 people:\n");

    for (int i = 0; i < size; i++) {
      printf("Enter Name:");
      scanf("%s", p[i].name);
      printf("Enter ID:");
      scanf("%d", &p[i].ID);
    };

    goto choice;

    break;

  case 2:
    printf("Enter ID number to delete:\n");
    scanf("%d", &id);

    for (int i = 0; i < size; i++) {
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
      strcpy(d, p[index].name);
      p[index].ID = 0;
      printf("Data deleted");
    }

    goto choice;
    break;

  case 3:
    printf("Enter ID number to modify:\n");
    scanf("%d", &index);
    printf("Enter Name:");
    scanf("%s", p[index].name);
    printf("Enter ID:");
    scanf("%d", &p[index].ID);
    goto choice;
    break;

  case 4:
    printf("Enter ID number to display:\n");
    scanf("%d", &id);

    for (int i = 0; i < size; i++) {
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
    scanf("%d", &id);

    for (int i = 0; i < size; i++) {
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
    for (int i = 0; i < size; i++) {
      printf("%d:%s , ", p[i].ID, p[i].name);
    }

    goto choice;
    break;

  default:
    exit(0);
  }
}
