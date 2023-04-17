#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int minValueIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minValueIndex])
				minValueIndex = j;
		}
		int temp = arr[i];
		arr[i] = arr[minValueIndex];
		arr[minValueIndex] = temp;
	}

}

int main() {

	int arr[] = { 4,3,2,1 };
	selectionSort(arr, 4);
	for (int i = 0; i < 4; i++) {
		printf("%d ", arr[i]);
	}
}