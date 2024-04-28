#include <stdio.h>
int main() {
  int SIZE;
  printf("Enter the quantity of numbers to put: ");
  scanf("%d", &SIZE);
  int arr[SIZE];

  printf("Enter numbers in ascending order:\n");
  for (int i = 0; i < SIZE; i++) {
    scanf("%d", &arr[i]);
  }

  int search;
  printf("Enter number to search: ");
  scanf("%d", &search);

  int low = 0, high = SIZE - 1, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] == search) {
      printf("Number found at position %d\n", mid + 1);
      return 0;
    } else if (arr[mid] < search) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
}
