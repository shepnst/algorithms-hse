#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#define ARR_SIZE 10
#define search

#ifdef insert
void printArray(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {
	int intArray[ARR_SIZE] = {0,1,2,3,4,5,6,7,8,9,-1 };
	//printf("initial arra:\n");
	//printArray(intArray, ar_size);//первонаальный массив
	int value = 99;
	int insertion_index = 5;
	for (int i = ARR_SIZE; i > insertion_index; --i) {
		intArray[i] = intArray[i - 1];//сдвиг элементов налево
	}
	intArray[insertion_index] = value;
	printf("after insertion:\n");
	printArray(intArray, ARR_SIZE);
}
#endif
#ifdef deletion
void printArray(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main(){
    int array[ARR_SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int deleteIndex = 4;
    int arrayActualLen = ARR_SIZE;
 
    printf("Initial array:\n");
    printArray(array, ARR_SIZE);

    // Delete element - move affected elements one position left
    for (int i = deleteIndex + 1; i < ARR_SIZE; i++)
    {
        array[i - 1] = array[i];
    }
    // Change the array's actual length
    arrayActualLen--;

    // Print the resulting array
    printf("New array size = %d \n", arrayActualLen);
    printf("Array after deleting value at index %d \n", deleteIndex);
    printArray(array, arrayActualLen);

    return 0;
}
#endif
#ifdef search
void printArray(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {
	int array[ARR_SIZE] = { 0, 11, 2, 33, 24, 5, 16, 37, 85, 99 };
	// Target to find
	int elementToFind = 16;
	// Variable for resulting index, initialize it to some bad value to check if it is changed finally
	int indexFound = -1;
	printf("Initial array:\n");
	printArray(array, ARR_SIZE);
	for (int i = 0; i < ARR_SIZE; i++)
	{
		if (array[i] == elementToFind)
		{
			indexFound = i;
			break;
		}
	}
	if (indexFound != -1)
		printf("Element %d is found at index %d \n", elementToFind, indexFound);
	else
		printf("Element %d is not found\n", elementToFind, indexFound);

	return 0;


}
#endif
