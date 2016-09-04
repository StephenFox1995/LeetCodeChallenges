#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *array;
  int elements;
} m_array;

void m_array_add(m_array *array, int element) {
  // If only one element we can just allocate the memory for it.
  if (array->elements == 0) {
    array->array = (int*)malloc(sizeof(int));
    array->array[0] = element;
    array->elements = array->elements + 1;  
  } else {
    // Adding more elements we need to realloc and add
    // space for another element.
    array->array = (int*)realloc(array->array, sizeof(array->array) + sizeof(int));
    array->elements = array->elements + 1;
    array->array[array->elements - 1] = element;
  }
}

int m_array_find_num(m_array array, int element) {
  for (int i = 0; i < array.elements; i++) {
    if (array.array[i] == element) {
      return 1;
    } else {
      return 0;
    }
  }
  return 0;
}


int* intersection(int *nums1, int nums1Length, int *nums2, int nums2length, int *returnSize) {
  int rSize = 0;
  m_array intersection;
  intersection.elements = 0;
  for (int i = 0; i < nums1Length; i++) {
    for (int j = 0; j < nums2length; j++) {
      if (nums1[i] == nums2[j]) {
        // Check if the number has already been accounted for in the intersection.
        if (m_array_find_num(intersection, nums1[i]) == 0) { 
          m_array_add(&intersection, nums1[i]);
        }
      }
    }
  }
  *returnSize = intersection.elements;
  return intersection.array;
}


int main(int argc, char *argv[]) {
  int nums1[] = {1, 3, 4, 1, 5, 10};
  int nums2[] = {2, 3, 4, 5, 20};
  int numsSize1 = sizeof(nums1) / sizeof(int);
  int numsSize2 = sizeof(nums2) / sizeof(int);
  int returnSize = 0; 
  int* intersect = intersection(nums1, numsSize1, nums2, numsSize2, &returnSize);
  
  printf("Return size: %d.\n", returnSize);
  printf("Intersection [\n");
  for (int i = 0; i < returnSize; i++) {
    printf("\t%d\n", intersect[i]);
  }
  printf("]\n");
}