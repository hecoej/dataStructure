#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
} listNode;
listPointer first = NULL;

listPointer insert_front(listPointer, int);
listPointer insert_last(listPointer, int);
void print_node(listPointer);
listPointer delete_odd_node(listPointer);
listPointer deleteAll(listPointer);

int main() {
	int data;
	listPointer first = NULL;
	FILE* fp = fopen("input.txt", "r");
	while (!feof(fp)) {
		fscanf(fp, "%d", &data);
		first = insert_last(first, data);
	}
	print_node(first);

	first->link = delete_odd_node(first->link);
	printf("\nAfter deleting nodes with odd value\n");
	print_node(first);
	first->link = deleteAll(first->link);
	print_node(first);
}

void print_node(listPointer first) {
	listPointer ptr = first->link;
	printf("The Circularly Linked List contains:\n");
	if (ptr == NULL) {
		printf("연결리스트가 비었습니다.\n");
		return;
	}
	do {
		printf("%p, %d, %p\n", ptr, ptr->data, ptr->link);
		ptr = ptr->link;
	} while (ptr != first->link);
}

listPointer insert_front(listPointer first, int data) {
	listPointer temp = (listPointer)malloc(sizeof(*temp));
	temp->data = data;

	if (first == NULL) {
		first = temp;
		temp->link = temp; //자기 자신 가리키기
	}
	else {
		temp->link = first->link;
		first->link = temp;
	}
	return first;
}

listPointer insert_last(listPointer first, int data) {
	listPointer temp = (listPointer)malloc(sizeof(*temp));
	temp->data = data;
	
	if (first == NULL) {
		first = temp;
		temp->link = temp; //자기 자신 가리키기
	}
	else {
		temp->link = first->link;
		first->link = temp;
		first = temp;
	}
	return first;
}

listPointer delete_odd_node(listPointer ptr) {
	listPointer prev, cur;
	prev = cur = ptr;

	do {
		if (cur->data % 2 == 1) {
			if (cur == ptr) {
				ptr = ptr->link;
				cur = ptr;
				prev->link = ptr;
				free(prev);
			}
			else {
				prev->link = cur->link;
				listPointer temp = cur;
				cur = cur->link;
				free(temp);
			}
		}
		else {
			prev = cur;
			cur = cur->link;
		}
	} while (cur != ptr);
	return ptr;
}

listPointer deleteAll(listPointer first) {
	listPointer next, cur;
	next = cur = first;
	do {
		next = cur->link;
		free(cur);
		cur = next;
	} while (cur != first);

	first = NULL;
	return first;
}