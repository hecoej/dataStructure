#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_ARY_SIZE 15

void binarySearch(int searchNum, int arr[], int n);
void selectionSort(int arr[], int n);
int main() {

	int arr[MAX_ARY_SIZE];
	FILE* fp;
	fp = fopen("input1.txt", "r");
	//1
	for (int i = 0; i < MAX_ARY_SIZE; i++) {
		fscanf(fp, "%d ", &arr[i]);
	}
	printf("���� ��:\n");
	for (int i = 0; i < MAX_ARY_SIZE; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	//2
	selectionSort(arr, MAX_ARY_SIZE);
	printf("���� ��:\n");
	for (int i = 0; i < MAX_ARY_SIZE; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	//3
	int searchNum;
	printf("ã�� ���ڸ� �Է��ϼ��� >> ");
	scanf("%d", &searchNum);
	printf("���� Ž�� ��:\n");
	binarySearch(searchNum, arr, MAX_ARY_SIZE);	
}

void selectionSort(int arr[], int n) {
	int temp;
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

void binarySearch(int searchNum, int arr[], int n) {
	int left = 0;
	int right = MAX_ARY_SIZE - 1;
	while (left <= right) {
		int middle = (left + right) / 2;
		printf("%d ", arr[middle]);
		if (searchNum < arr[middle]) {
			right = middle - 1;
		}
		else if (searchNum == arr[middle]) {
			return;
		}
		else {
			left = middle + 1;
		}
	}	
}