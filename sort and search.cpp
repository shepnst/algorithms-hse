
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void printArray(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void arr_init(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &arr[i]);
	}
}

void binary(int target, int arr[], int size) {
	int left = 0;
	int right = size-1;
	
	int search[100];
	int j = 0;
	int count = 0;
	int flag = 0;
	int result[1];
	while (left <= right) {
		flag = 1;
		int middle = round((left + right) / 2);
		search[j] = middle;
		j++;
		count++;
		
		if (target == arr[middle]) {
			//printf("Target is found at: %d\n", middle);
			result[0] = middle;
			break;
		}

		else if (target > arr[middle]) {

			left = middle + 1;
		}

		else if (target < arr[middle]) {
			right = middle - 1;
		}
		if (left > right) {
			flag = 0;
		}
	}
	if (flag == 1) {
		printf("Search history: ");
		for (int i = 0; i < count; i++) {
			printf("%d(%d) ", arr[search[i]], search[i]);
		}
		printf("\nTarget is found at: %d\n", result[0]);
	}
	if (flag == 0) {
		printf("Search history: ");
		for (int i = 0; i < count; i++) {
			printf("%d(%d) ", arr[search[i]], search[i]);
		}
		printf("\nNo targets");
	}
	
}



int main()
{

	int size, target;
	scanf_s("%d %d", &size, &target);
	int* arr = (int*)malloc(size * sizeof(int));
	arr_init(arr, size);
	printf("Initial array:\n");
	printArray(arr, size);
	printf("Target element: %d\n", target);
	binary(target, arr, size);

}
