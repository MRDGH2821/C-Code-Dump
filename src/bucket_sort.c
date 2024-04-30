/**
 * @file bucket_sort.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief
 * @version 0.1
 * @date 2024-04-30
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 7
#define BUCKETS 6
#define BUCKET_CAPACITY 10

struct Node {
  int data;
  struct Node *next;
};

void bucket_sort(int array[]);
struct Node *insertion_sort(struct Node *list);
void print_array(int array[]);
void print_buckets(struct Node *list);
int get_bucket_index(int value);

void int_scan(int *number) {
  char s[sizeof(number)] = {};
  fgets(s, sizeof(number), stdin);
  *number = strtol(s, NULL, 10);
}

/**
 * @brief Sorting function
 *
 * @param array
 */
void bucket_sort(int array[]) {
  int i, j;
  struct Node **buckets;
  // Create buckets and allocate memory size
  buckets = (struct Node **)malloc(sizeof(struct Node *) * BUCKETS);

  // Initialize empty buckets
  for (i = 0; i < BUCKETS; ++i) {
    buckets[i] = NULL;
  }

  // Fill the buckets with respective elements
  for (i = 0; i < ARRAY_SIZE; ++i) {
    struct Node *current;
    int pos = get_bucket_index(array[i]);
    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = array[i];
    current->next = buckets[pos];
    buckets[pos] = current;
  }

  // Print the buckets along with their elements
  for (i = 0; i < BUCKETS; i++) {
    printf("Bucket[%d]: ", i);
    print_buckets(buckets[i]);
    printf("\n");
  }

  // Sort the elements of each bucket
  for (i = 0; i < BUCKETS; ++i) {
    buckets[i] = insertion_sort(buckets[i]);
  }

  printf("-------------\n");
  printf("Bucktets after sorting\n");

  for (i = 0; i < BUCKETS; i++) {
    printf("Bucket[%d]: ", i);
    print_buckets(buckets[i]);
    printf("\n");
  }

  // Put sorted elements on arr
  for (j = 0, i = 0; i < BUCKETS; ++i) {
    struct Node *node;
    node = buckets[i];

    while (node) {
      array[j++] = node->data;
      node = node->next;
    }
  }

  return;
}

/**
 * @brief Function to sort the elements of each bucket
 *
 * @param list
 * @return struct Node*
 */
struct Node *insertion_sort(struct Node *list) {
  struct Node *k, *nodeList;

  if (list == 0 || list->next == 0) {
    return list;
  }

  nodeList = list;
  k = list->next;
  nodeList->next = 0;

  while (k != 0) {
    struct Node *ptr;

    if (nodeList->data > k->data) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = nodeList;
      nodeList = tmp;
      continue;
    }

    for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
      if (ptr->next->data > k->data) {
        break;
      }
    }

    if (ptr->next != 0) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = ptr->next;
      ptr->next = tmp;
      continue;

    } else {
      ptr->next = k;
      k = k->next;
      ptr->next->next = 0;
      continue;
    }
  }

  return nodeList;
}

/**
 * @brief Get the bucket index number
 *
 * @param value
 * @return int
 */
int get_bucket_index(int value) { return value / BUCKET_CAPACITY; }

/**
 * @brief Prints the array
 *
 * @param array
 */
void print_array(int array[]) {
  int i;

  for (i = 0; i < ARRAY_SIZE; ++i) {
    printf("%d ", array[i]);
  }

  printf("\n");
}

/**
 * @brief Prints the buckets
 *
 * @param list
 */
void print_buckets(struct Node *list) {
  struct Node *cur = list;

  while (cur) {
    printf("%d ", cur->data);
    cur = cur->next;
  }
}

// Driver code
int main(void) {
  int array[ARRAY_SIZE];
  printf("Enter max double digit numbers below 59:\n");

  for (int i = 0; i < ARRAY_SIZE; i++) {
    int_scan(&array[i]);
  }

  printf("-------------\n");
  printf("Initial array: ");
  print_array(array);
  printf("-------------\n");
  bucket_sort(array);
  printf("-------------\n");
  printf("Sorted array: ");
  print_array(array);
  return 0;
}
