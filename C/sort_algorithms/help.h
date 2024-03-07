# include <stdio.h>
# include <stdlib.h>

void printArr(int arr[], int len){
    int i;
    for(i = 0;i < len;i++){
        printf("%d ", arr[i]);
    }
}

void swap(int *arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}