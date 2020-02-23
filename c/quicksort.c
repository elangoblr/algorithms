#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int *a, int start, int end){
  int pivot = end;
  int i = start - 1;
  for (int j = start; j < end; j++){
    if (a[j] < a[pivot]){
      i++;
      swap(&a[j], &a[i]);
    }
  }
  swap(&a[++i], &a[pivot]);
  return i;
}

void mquicksort(int *a, int start, int end){
  if (start < end){
    int pivot = partition(a, start, end);
    mquicksort(a, start, pivot - 1);
    mquicksort(a, pivot + 1, end);
  }
}

void quicksort(int *a, int size){
  mquicksort(a, 0, size - 1);
}

int main(int argc, char **argv){
  //int a[] = {10,9,8,7,6,5,4,3,2,1};
  //int a[] = {10,9,8,7};
  int a[] = {1,2,3,4,5,6,7,8,9,10};
  int size = sizeof(a)/sizeof(int);
  for (int i = 0; i < size; i++)
    printf("%d ", a[i]);
  printf("\n");
  quicksort(a, size);
  for (int i = 0; i < size; i++)
    printf("%d ", a[i]);
  printf("\n");
  return 0;
}
