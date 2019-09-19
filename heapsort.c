#include <stdio.h>
#include <stdlib.h>

/* swap two values */
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

/* standard max-heapify algorithm */
void heapify(int *arr, int size, int root){
	/* assume root index as largest for now */
	int largest = root;

	/*
	 * left child and right child for a complete binary or almost complete
	 * binary tree (zero index array).
	 */
	int lChild = 2 * root + 1;
	int rChild = 2 * root + 2;

	/*
	 * check the left child and right child if they are larger than the 
	 * current largest, which is root
	 */
	if (lChild < size && arr[lChild] > arr[largest])
		largest = lChild;
	if (rChild < size && arr[rChild] > arr[largest])
		largest = rChild;

	/*
	 * the assumed root as largest is changed, swap (move the child to the
	 * largest position.
	 */
	if (largest != root){
		swap(&arr[largest], &arr[root]);
		/*
		 * now that the subtree has changed, heapify the subtree,
		 * rooted at the largest node.
		 */
		heapify(arr, size, largest);
	}
}

void myheapsort(int *a, int n){
	/*
	 * n/2 - 1 until 0 of the given array is where the non-leaf node starts
	 * The leaf nodes already has max-heap property.
	 */
	for (int i = n/2 -1 ; i >= 0; i--)
		heapify(a, n, i);

	/*
	 * After the above forloop, we have the maximum element in the index
	 * zero. Move that element to the end, remember we are sorting the
	 * array ascending; max is moved to last. Once the element is moved to
	 * last, do a heapify from 0 until n-1 and so on. We will have sorted
	 * array.
	 */
	for (int i = n - 1; i >= 0; i--){
		/* move the zero index element to end of array */
		swap(&a[0], &a[i]);

		/* now heapify the remaining elements, note i is decreasing */
		heapify(a, i, 0);
	}
}

int main(){
	int a[] = {9, 8, 11, 0, 13, 14};
	int arraySize = sizeof(a)/sizeof(a[0]);
	myheapsort(a, arraySize);
	/* print the sorted array */
	for (int i = 0; i < arraySize; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
