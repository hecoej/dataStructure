#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_SIZE 20

typedef struct {
	int id; // unique id
	char name[MAX_NAME_SIZE]; // last name
} element;
element *queue;
int capacity = 2;
int front = 0;
int rear = 0;

void addq(element);
void deleteq();
void copy();
void qprint();
void isFull();
void isEmpty();

int main() {
	char op[20];
	FILE* fp = fopen("input.txt", "r");
	element student = { NULL };

	queue = (element*)malloc(capacity * sizeof(element));

	while (!feof(fp)) {
		fscanf(fp, "%s", op);
		if (strcmp(op, "add") == 0) {
			fscanf(fp, "%d %s", &student.id, &student.name);
			addq(student);
		}
		else if (strcmp(op, "delete") == 0) {
			deleteq();
		}
		else if (strcmp(op, "qprint") == 0) {
			qprint();
		}
		else if (strcmp(op, "quit") == 0) {
			printf("enf of program!\n");
			break;
		}
		else {
			fgets(op, 100, fp);
			printf("wrong command! try again!\n");
		}
	}
}

void addq(element item) {
	rear = (rear + 1) % capacity;
	if (front == rear) {
		isFull();
		queue[++rear] = item;
		qprint();
	}
	else {
		queue[rear] = item;
	}
}

void deleteq() {
	if (front == rear) {
		isEmpty();
	}
	else
		front = (front + 1) % capacity;
}

void isFull() {
	int start;
	// 새 배열 만들기
	element* newQueue;
	newQueue = (element*)malloc(2 * capacity * sizeof(*queue));

	start = (front + 1) % capacity;
	if (start < 2) {
		// no wrap around
		copy(queue + start, queue + start + capacity - 1, newQueue);
	}
	else {
		//queue wraps around
		copy(queue + start, queue + capacity, newQueue);
		copy(queue, queue + rear + 1, newQueue + capacity - start);
	}

	front = 2 * capacity - 1;
	rear = capacity - 2;
	capacity *= 2;
	free(queue);
	queue = newQueue;

	printf("queue capacity is doubled.\n");
	printf("current queue capacity is %d\n", capacity);
}
void copy(element* a, element* b, element* c) {
	while (a != b) {
		*c++ = *a++;
	}
}

void isEmpty() {
	printf("Queue is empty, cannot delete element.\n");
}

void qprint() {
	int i = (front + 1) % capacity;
	while (i != front) {
		if (i == rear) {
			printf("%d %s\n", queue[i].id, queue[i].name);
			break;
		}
		printf("%d %s\n", queue[i].id, queue[i].name);
		i = (i + 1) % capacity;
	}
	puts("");
}