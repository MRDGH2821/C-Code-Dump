#include <stdio.h>
#include <stdlib.h>
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
    scanf("%d", &ch);

    switch (ch) {
    case 1:
      printf("Enter Data: ");
      scanf("%d", dat);
      push(dat, top);
      break;

    case 2:
      pop(top);
      break;

    case 3:
      display(top);
      break;
    }
  }
}
