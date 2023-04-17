#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
	int data;
	struct listNode* link;
} listNode;
listNode* first = NULL;

void insert_node(int data);
void delete_node(int data);
void print_node();

int main() {
	int n;
	FILE* fp = fopen("input.txt", "r");
	
	while (!feof(fp)) {
		fscanf(fp, "%d", &n);
		insert_node(n);
	}
	print_node();

	rewind(fp);
	while (!feof(fp)) {
		fscanf(fp, "%d", &n);
		int temp = n;
		if (temp % 2 == 1) {
			delete_node(n);
		}
	}
	printf("After deleting nodes odd value\n");
	print_node();
}

void insert_node(int data) {
	listNode* newNode, *ptr;
	newNode = (listNode*)malloc(sizeof(*newNode));
	newNode->data = data;
	newNode->link = NULL;
	
	//���� ��
	//1. ��� null�϶�
	if (first == NULL) {
		first = newNode;
	}
	//head �տ� ����
	else if (first->data >= newNode->data) {
		newNode->link = first;
		first = newNode;
		return;
	}
	//�߰��� ���� 10 30 [20]
	else {
		for (ptr = first; ptr->link; ptr = ptr->link) {
			if (ptr->data <= newNode->data && ptr->link->data >= newNode) {
				newNode->link = ptr->link;
				ptr->link = newNode;
				return;
			}
		}
		//�� �ڿ� ����
		ptr->link = newNode;
	}	 
}

void delete_node(int data) {
	listNode* prev, *cur, *newNode;
	prev = cur = first;

	//���� �� ����
	if (first->data == data) {
		first = cur->link;
		free(cur);
		return;
	}

	//�߰��̳� ������ ����
	for (; cur; cur = cur->link) {
		if (cur->data == data) {
			prev->link = cur->link;
			cur->link = NULL;
			free(cur);
			return;
		}
		prev = cur;
	}

}

void print_node() {
	listNode* ptr = first;
	printf("The ordered list contains:\n");

	for(; ptr->link; ptr=ptr->link)
		printf("(%p,\t%d,\t%p)\n", ptr, ptr->data, ptr->link);
	printf("(%p,\t%d,\t%p)\n", ptr, ptr->data, ptr->link);
}