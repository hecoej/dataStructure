#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void insertionSort(int arr[], int n) {

	for (int i = 1; i < n; i++) {
		int insertingData = arr[i];
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > insertingData) {
				arr[j + 1] = arr[j];
			}
			else
				break;
		}
		arr[j + 1] = insertingData;
	}
}

int main() {
	int arr[] = { 4,1,5,3,6,2 };
	insertionSort(arr, 6);
	for (int i = 0; i < 6; i++) {
		printf("%d ", arr[i]);
	}
}