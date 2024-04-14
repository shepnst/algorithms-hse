#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define SIZE 10000

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;

}



int parent(int i) {
	return (i -1)/2;
}

int left(int i) {
	return 2 * i + 1;
}

int right(int i) {
	return 2 * i + 2;
}

void sift_up(int heap[], int curr) {
	while (curr != 0 && heap[parent(curr)] < heap[curr]) {
		swap(&heap[parent(curr)], &heap[curr]);
		curr = parent(curr);
	}

}



void insert(int heap[], int value, int* n) {
	heap[*n] = value;
	*n = *n + 1;
	int curr = *n - 1;
	sift_up(heap, curr);
}


void sift_down(int heap[], int n, int curr) {
	int left_child = left(curr);
	int right_child = right(curr);
	int big_ind = curr;
	if (left_child<=n && heap[left_child] > heap[big_ind]) {
		big_ind = left_child;
	}
	if (right_child <= n && heap[right_child] > heap[big_ind]) {
		big_ind = right_child;
	}

	if (big_ind != curr) {
		swap(&heap[curr], &heap[big_ind]);
		sift_down(heap, n, big_ind);
	}

}


int extract(int heap[],  int* n) {
	int max = heap[0];
	heap[0] = heap[*n - 1];
	*n = *n - 1;
	sift_down(heap, *n, 0);
	return max;
}


void print_heap(int heap[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", heap[i]);
	}
	printf("\n");
}



int main()
{
	int n = 0;
	int heap[SIZE];
	int t;
	int value;
	int max_it;
	cin >> t;
	string task;
	vector<int> ans;
	for (int i = 0; i < t; i++) {
		cin >> task;
		if (task[0] == 'I') {
			cin >> value;
			insert(heap, value, &n);
		}
		else {
			max_it = extract(heap, &n);
			ans.push_back(max_it);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	

}

