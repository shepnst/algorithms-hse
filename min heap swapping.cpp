
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#define SIZE 1000
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;

}


int parent(int i) {
	return (i - 1) / 2;
}

int left(int i) {
	return 2 * i+1;
}

int right(int i) {
	return 2 * i + 2;
}

void sift_down(vector<int>&heap, int n, int curr, vector<pair<int, int>>&swaps) {
	int min_ind = curr;
	int left_child = left(curr);
	int right_child = right(curr);
	
	if (left_child < n && heap[left_child] < heap[min_ind]) {
		min_ind = left_child;
	}
	if (right_child < n && heap[right_child] < heap[min_ind]) {
		min_ind = right_child;
	}

	if (min_ind != curr) {
		swap(&heap[min_ind], &heap[curr]);
		swaps.push_back(make_pair(curr,min_ind));
		sift_down(heap, n, min_ind, swaps);
		
	}
}



int main()
{
	
	int n;
	cin >> n;
	vector<int>heap(n);
	for (int j = 0; j < n; j++) {
		cin >> heap[j];
	}
	vector<pair<int, int>> swaps;
	for (int i = n/2-1; i >= 0; i--) {
		sift_down(heap, n, i, swaps);
	}
	cout << swaps.size()<<endl;
	for (pair<int, int>swap:swaps) {
		cout << swap.first << " " << swap.second << endl;
	}
}

