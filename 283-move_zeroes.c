#include <stdio.h>

void moveZeroes(int* nums, int numSize) {
  for (int i = 0; i < numSize; i++) {
    if (nums[i] == 0) { // If current number is 0, we want to push to end.
      for (int j = i; j < numSize - 1; j++) {
        nums[j] = nums[j + 1]; // Shift all numbers all the way back.
      }
      nums[numSize - 1] = 0;
    }
  }
}

int main(int argc, char *argv[]) {
  int nums[] = {0, 1, 0, 3, 12, 0, 11, 0};
  int size = sizeof(nums) / sizeof(int);
  moveZeroes(nums, size);
  printf("[");
  for (int i = 0; i < size; i++) {
    printf("%d ", nums[i]);
  }
  printf("]\n");
}