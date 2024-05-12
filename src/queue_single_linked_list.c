/**
 * @file queue_single_linked_list.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief Implementation of Single Linked List using Queue
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
struct node {
  int data;
  struct node *next;
};

void insertBeg(int dat, struct node *top) {
  struct node *new_node;
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = dat;
  new_node->next = top;
  top = new_node;
}

void deleteLast(struct node *top) {
  struct node *old_node;
  old_node = top;
  top = top->next;
  free(old_node);
}

void display(struct node *top) {
  struct node *nd;
  nd = top;

  while (nd->next != NULL) {
    printf("%d -> ", nd->data);
  }
}

int main() {
  struct node *top;
  top = (struct node *)malloc(sizeof(struct node));
  top->data = 0;
  top->next = NULL;
  int ch = 1, dat;

  while (ch != 0) {
    printf("Queue Operations\n\n1.Insert\n2.Delete\n3.Display\n0.Exit\n\nEnter "
           "choice:");
    int_scan(&ch);

    switch (ch) {
    case 1:
      printf("Enter Data: ");
      int_scan(&dat);
      insertBeg(dat, top);
      break;

    case 2:
      deleteLast(top);
      break;

    case 3:
      display(top);
      break;
    }
  }
}
