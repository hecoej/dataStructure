/*

2.�Է� ���� ������ �迭�� ���� ���� ���� ���� �Լ� make2dArray()�� �����ϸ�, �Լ�
make2dArray()�� ���� ���� ���� ���� ��ŭ �������� �޸𸮸� �Ҵ� �޾� �������� 100����
���� ������ �޸𸮸� �ʱ�ȭ ��Ų ��, �ּҰ��� ��ȯ�Ѵ�.
int main()
{
int **ipp;
int i, j, rows, cols;
printf("������ �迭�� ��� ���� ���� �Է� �ϼ��� : ");
scanf_s("%d %d",&rows, &cols);
ipp=make2dArray(rows, cols);
for(i=0; i<rows; i++)
for(j=0; j<cols; j++)
printf("ipp[%d] =%d ", i, ipp[i][j]);
return 0; // break point ����
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int** make2dArray(int, int);
int main()
{
	int** ipp;
	int i, j, rows, cols;
	printf("������ �迭�� ��� ���� ���� �Է� �ϼ��� : ");
	scanf_s("%d %d", &rows, &cols);
	ipp = make2dArray(rows, cols);
	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			printf("ipp[%d][%d] =%d ", i, j, ipp[i][j]);
	return 0; // break point ����
}

int** make2dArray(int row, int col) {
	int** x;
	x = (int *)malloc(row * sizeof(*x));

	for (int i = 0; i < row; i++) {
		x[i] = (int**)malloc(col * sizeof(**x));
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			x[i][j] = rand()%100;
		}
	}
	return x;
}