#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_QUEUE_SIZE 3
#define MAX_NAME_SIZE 20

typedef struct {
	int id; // unique id
	char name[MAX_NAME_SIZE]; // last name
} element;
element queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

void addq(element);
void deleteq();
void qprint();
void isFull();
void isEmpty();

int main() {
	char op[20];
	FILE* fp = fopen("input.txt", "r");
	element student = { NULL };

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
			break;
		}
		else {
			fgets(op, 100, fp);
			printf("wrong command! try again!\n");
		}
	}
}

void addq(element item) {
	if (rear == MAX_QUEUE_SIZE - 1 && front == -1) {
		isFull();
	}
	
	else if (front >= 0) {
		printf("data shift\n");
		while (front == -1) {
			int i = 0;
			queue[i] = queue[i + 1];
			i++;
			rear--;
			front--;
		}
		queue[++rear] = item;
	}
	
	else
		queue[++rear] = item;
}

void deleteq() {
	if (front == rear) {
		isEmpty();
	}
	else
		queue[++front];
}

void isFull() {
	printf("queue is full, not added\n");
}

void isEmpty() {
	printf("Queue is empty, cannot delete element.\n");
}

void qprint() {
	for (int i = front+1; i <= rear; i++) {
		printf("%d %s\n", queue[i].id, queue[i].name);
	}
	printf("\n");
}