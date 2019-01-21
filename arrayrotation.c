#include<stdio.h>
#include<stdlib.h>

void rotatepartial(int *arr, int start, int end){
    int tmp;
    while(start < end){
        tmp = arr[start];
        arr[start++] = arr[end];
        arr[end--] = tmp;
    }
}

void rotatearray(int *arr, int arrSize, int spaces){
    if (arrSize < spaces)
        return;
    int rotation_index = arrSize - spaces;
    rotatepartial(arr, 0, rotation_index - 1);
    rotatepartial(arr, rotation_index, arrSize - 1);
    rotatepartial(arr, 0, arrSize - 1);
}

void printarray(int *arr, int n){
    printf("[ ");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    //int arr[] = {0};
    int size = sizeof(arr)/sizeof(arr[0]);
    printarray(arr, size);
    rotatearray(arr, size, 3);
    printarray(arr, size);
}
