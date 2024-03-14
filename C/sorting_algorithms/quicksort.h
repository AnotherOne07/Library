# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "help.h"

// This function takes last element as pivot,
// places the pivot element at its correct position
// in sorted array, and places all smaller to left 
// of pivot and all greater elements to right of pivot
int partition(int *arr, int low, int high) {
  // The pivot will be the latest element in array
  // In this case we are using always the last element but exists some other
  // options
  int pivot = arr[high];

  // index of smaller element and indicates the right position of pivot found so
  // far
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      // if pivot is higher than current index then
      // increment index of smaller element
      i++;
      swap(arr, i, j);
    }
  }
  swap(arr, i + 1, high);
  return(i + 1);
}

// The function that implements QuickSort
// arr[] --> array to be sorted,
// low --> Starting index
// high --> Ending index
void quickSort(int *arr, int low, int high) {
  int partitionIndex;

  if (low < high) {
    // pi is partitioning index, arr[p] is now at right place
    partitionIndex = partition(arr, low, high);

    // Separately sort elements before
    // and after partition index
    // it does it recursively
    quickSort(arr, low, partitionIndex - 1); // Starting index and partitioned index minus 1
    quickSort(arr, partitionIndex + 1, high); // Partitioned index plus 1 and ending index
  }
}

void quickSortByLastElement(int* arr){
    int n;
    n = sizeof(arr)/sizeof(int);

    printf("%d", n);
}

// int main() {
//   int arr[] = {10, 7, 8, 9, 1, 5};
//   int N = 6;

//   // Function call
//   printf("Sorted array:");
//   quickSort(arr, 0, N - 1);
//   for (int i = 0; i < N; i++)
//     printf(" %d", arr[i]);

//   return 0;
// }
