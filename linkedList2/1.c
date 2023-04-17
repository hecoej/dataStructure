#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct element{
	char name[100];
	char job[100];
	char gender[50];
} element;

typedef struct listnode {
	element data;
	struct listnode* link;
}listnode;
listnode* head = NULL;
listnode* menhead = NULL;
listnode* womenhead = NULL;
listnode* ptr, * menptr, * womenptr;

void insert_node(element item, listnode**, listnode**);
void print_node(listnode* first);
listnode* concatenate(listnode*, listnode*);
listnode* invert(listnode*);

int main() {
	element e[10];
	
	FILE* fp = fopen("input.txt", "r");
	int i = 0;
	while (!feof(fp)) {
		fscanf(fp, "%s %s %s", e[i].name, e[i].job, e[i].gender);
		insert_node(e[i], &head, &ptr);
		if (strcmp(e[i].gender, "남자") == 0) {
			insert_node(e[i], &menhead, &menptr);
		}
		else {
			insert_node(e[i], &womenhead, &womenptr);
		}
	}
	printf("전체 리스트\n");
	print_node(head);
	printf("남자 리스트\n");
	print_node(menhead);
	printf("여자 리스트\n");
	print_node(womenhead);

	printf("합친 리스트\n");
	listnode* ptr = concatenate(womenhead, menhead);
	print_node(ptr);
	
	printf("역순 리스트\n");
	ptr = invert(womenhead);
	print_node(ptr);

	return 0;
}

void insert_node(element item, listnode** head, listnode** ptr) {
	listnode* newNode;
	newNode = (listnode*)malloc(sizeof(*newNode));
	newNode->data = item;
	newNode->link = NULL;

	if (*head == NULL) {
		*head = newNode;
		*ptr = *head;
	}
	else {
		newNode->link = (*ptr)->link;
		(* ptr)->link = newNode;
		(*ptr) = newNode; // ptr을 새로운 노드로 갱신
	}
}

void print_node(listnode* first) {
	listnode* c = first;
	for (; c; c = c->link) {
		printf("(%p, %s, %s, %s, %p)\n", c, c->data.name,
			c->data.job, c->data.gender, c->link);
	}
}

listnode* concatenate(listnode* head1, listnode* head2) {
	listnode* ptr;
	if (head1 == NULL) {
		return head2;
	}
	if (head2 == NULL) {
		return head1;
	}
	for (ptr = head1; ptr->link; ptr = ptr->link);
	ptr->link = head2;
	return head1;

}

listnode* invert(listnode* lead) {
	listnode* trail, * middle;
	middle = NULL;
	while (lead) {
		trail = middle;
		middle = lead;
		lead = lead->link;
		middle->link = trail;
	}
	return middle;

}