#include<stdio.h>
#include<stdlib.h>

/* a simple merge sort implementation */


/* merge function - merge two arrays in ascending order */
void merge(int *arr, int n, int *a, int na, int *b, int nb){
	int i, j, k;
	i = j = k = 0;
	while(i < na && j < nb){
		if (a[i] <= b[j])
			arr[k++] = a[i++];
		else if (b[j] <= a[i])
			arr[k++] = b[j++];
	}
	while(i < na)
		arr[k++] = a[i++];
	while(j < nb)
		arr[k++] = b[j++];
}


/* divide a given array of integers into two and sort them recursively */
void mymergesort(int *arr, int size){
	if (size < 2)
		return;
	int mid = size / 2;
	int *left = malloc(sizeof(int) * mid);
	int *right = malloc(sizeof(int) * (size - mid));
	for (int i = 0; i < mid; i++)
		left[i] = arr[i];
	for (int i = mid; i < size; i++)
		right[i - mid] = arr[i];
	mymergesort(left, mid);
	mymergesort(right, size - mid);
	merge(arr, size, left, mid, right, size - mid);
	free(left);
	free(right);
}

int main(){
	int arr[] = {6,6,5,5,5,5,4,3,2,1};
	//int arr[] = {1,2,3,4,5,6,6,6};
	int size = sizeof(arr)/sizeof(arr[0]);
	for (int i = 0; i < size; i++)
		printf("%d, ", arr[i]);
	printf("\n");
	mymergesort(arr, size);
	for (int i = 0; i < size; i++)
		printf("%d, ", arr[i]);
	printf("\n");
	return 0;
}
