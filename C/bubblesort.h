# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int len){
    // Loop Integer
    int i, j;
    // This variable will be use to break a loop if the current element is not higher than the next
    bool swapped;
    // The number of passes is array_length - 1
    for(i = 0;i < len - 1;i++){
        swapped = false;
        for(j = 0; j < len - i - 1;j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop then break
        // Because it means that the array is already ordered
        if(swapped == false)
            break;
    }
}