#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{/* reversed array
	int len;
	int* arr;
	printf("enter the size of the array:\n");
	scanf_s("%d", &len);
	arr = (int*)malloc(len * sizeof(int));
	for (int i = 0; i < len; i++) {
		scanf_s("%d", &arr[i]);
	}
	printf("\n");
	int for_swap;
	int left = 0;
	int right = len - 1;
	while (left < right) {
		for_swap = arr[left];
		arr[left] = arr[right];
		arr[right] = for_swap;
		left += 1;
		right -= 1;
	}
	printArray(arr, len);
	free(arr);
	*/
	/* changes of ellemnts
	int n, m;
	scanf_s("%d %d", &n, &m);
	int* arr;
	arr = (int*)malloc(n * sizeof(int));
	for (int k = 0; k < n; k++) {
		scanf_s("%d", &arr[k]);
	}
	int i, j;
	for (int t = 1; t <= m; t++) {
		scanf_s("%d %d", &i, &j);
		int swap;
		swap = arr[i];
		arr[i] = arr[j];
		arr[j] = swap;
	}
	printArray(arr, n);
	*/
	/* min out of two
	int n;
	scanf_s("%d", &n);
	int* arr1;
	arr1 = (int*)malloc(n * sizeof(int));
	for (int k = 0; k < n; k++) {
		scanf_s("%d", &arr1[k]);
	}
	int* arr2;
	arr2 = (int*)malloc(n * sizeof(int));
	for (int k = 0; k < n; k++) {
		scanf_s("%d", &arr2[k]);
	}
	int* c;
	c = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		if (arr1[i] < arr2[i]) {
			c[i] = arr1[i];
		}
		else {
			c[i] = arr2[i];
		}
	}
	printArray(c, n);
	*/
	/* sum of 2d array
	int n, m;
	scanf("%d %d", &n, &m);
	long long int arr[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%lld", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		long long int row_sum = 0;
		for (int j = 0; j < m; j++) {
			row_sum += arr[i][j];
		}
		printf("%lld ", row_sum);
	}
	printf("\n");
	for (int j = 0;j < m; j++) {
		long long int cul_sum = 0;
		for (int i = 0;j < n; i++) {
			cul_sum += arr[i][j];
		}
		printf("%lld ", cul_sum);
	}
	free(arr);
	return 0;
	*/
	int n;
	scanf_s("%d", &n);
	int* arr;
	arr = (int*)malloc(n * sizeof(int));
	for (int i=0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	int m;
	scanf_s("%d", &m);
	for (int j = 0; j < m; j++) {
		int q;
		scanf_s("%d", &q);
		if (q == 0) {
			int ind, val;
			scanf_s("%d %d", &ind, &val);
			if (ind < 1 || ind>n+1){
				continue;
			}
			arr = (int*)realloc(arr, (n + 1) * sizeof(int));
			for (int p = n; p >= ind; p--) {
				arr[p] = arr[p - 1];
			}
			
			arr[ind - 1] = val;
			n += 1;
		}
		else if (q == 1) {
			int ind;
			scanf_s("%d", &ind);
			if (ind < 1 || ind>n) {
				continue;
			}
			for (int i = ind - 1; i < n-1; i++)
			{
				arr[i] = arr[i+1];
			}
			arr = (int*)realloc(arr, (n - 1) * sizeof(int));
			n-= 1;

		}
		else {
			continue;
		}
		printArray(arr, n);
	}

}