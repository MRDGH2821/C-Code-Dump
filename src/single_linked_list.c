/**
 * @file single_linked_list.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief Implementation of Single Linked List
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

void insert(struct node nd, int ndata) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = ndata;
  nd.next = new_node;
  new_node->next = NULL;
}

void printList(struct node *node) {
  while (node != NULL) {
    printf("%d->", node->data);
    node = node->next;
  }
}

int main() {
  int ch = 1;
  int dt;
  struct node head;
  head.next = NULL;

  while (ch != 0) {
    printf("1.Insert\n2.Display\n0.Exit\n\n");
    int_scan(&ch);

    switch (ch) {
    case 1:
      printf("Enter number: ");
      int_scan(&dt);
      insert(head, dt);
      break;

    case 2:
      printList(&head);

    case 0:
      exit(0);
    }
  }
}
