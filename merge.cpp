#include <stdlib.h> 
#include <stdio.h> 
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

int* merge(int* a, int* b, int la, int lb) {
	int *c = (int*)calloc(la + lb, sizeof(int));
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < la && j < lb) {
		if (a[i] <= b[j]) {
			c[k] = a[i];
			k++;
			i++;
		}
		else {
			c[k] = b[j];
			k++;
			j++;
		}
	}
	while (i < la) {
		c[k] = a[i];
		k++;
		i++;
	}
	while (j < lb) {
		c[k] = b[j];
		k++;
		j++;
	}
	return c;
}
int* merge_sort(int* arr, int n) {
	if (n == 1)
		return arr;
	int *a = (int*)calloc(n / 2, sizeof(int));
	int *b = (int*)calloc(n / 2 + n % 2, sizeof(int));
	for (int i = 0; i < n / 2; i++)
		a[i] = arr[i];
	for (int i = 0; i < n / 2 + n % 2; i++)
		b[i] = arr[i + n / 2];
	a = merge_sort(a, n / 2);
	b = merge_sort(b, n / 2 + n % 2);
	arr = merge(a, b, n / 2, n / 2 + n % 2);
	printf("Left part: ");
	for (int i = 0; i < n / 2; i++)
		printf("%d ", a[i]);
	printf("\n");
	printf("Right part: ");
	for (int i = 0; i < n / 2 + n % 2; i++)
		printf("%d ", b[i]);
	printf("\n");
	printf("Merged parts: ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
	free(a);
	free(b);
	return arr;
}

int main() {
	int n;
	scanf_s("%d", &n);
	int *a = (int*)calloc(n, sizeof(int));
	arr_init(a, n);
	printf("Initial array:\n");
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n\n");
	merge_sort(a, n);
	return 0;
}