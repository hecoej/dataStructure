#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 5
#define MAX_NAME_SIZE 20

typedef struct {
	int id; // unique id
	char name[MAX_NAME_SIZE]; // last name
} element;
element stack[MAX_STACK_SIZE];
int top = -1;

void push(element);
void pop();
void isFull();
void isEmpty();
void sprint();

int main() {
	
	FILE* fp = fopen("input.txt", "r");
	int id;
	char op[20], name[MAX_NAME_SIZE];
	element student = {NULL};

	printf("<< stack oprations where MAX_STACK_SIZE is 5 >>\n");
	printf("The format of the stack op is as follows\n");
	printf("push 1 jung\npop\n\n*********************************************\n");

	while (!feof(fp)) {
		fscanf(fp, "%s", op);
		if (strcmp(op, "push") == 0) {
			fscanf(fp, "%d %s", &student.id, &student.name);
			push(student);
		}
		else if (strcmp(op, "pop") == 0) {
			pop();
		}
		else if (strcmp(op, "sprint") == 0) {
			sprint();
		}
		else if (strcmp(op, "quit") == 0) {
			break;
		}
		else {
			fgets(op, 100, fp);
			printf("\nwrong command! try again!\n");
		}
	}

}

void push(element item) {
	if (top >= MAX_STACK_SIZE - 1) {
		isFull();
	}
	else
		stack[++top] = item;
}

void pop() {
	if (top == -1)
		isEmpty();
	else
		stack[top--];
}

void isFull() {
	printf("stack is full, cannot add element\n");
	printf("current stack elements: \n");
	sprint();
}

void isEmpty() {
	printf("stack is empty, cannot delete element\n");
	printf("current stack elements: \n");
	sprint();
}

void sprint() {
	for (int i = top; i >= 0; i--) {
		printf("%d %s\n", stack[i].id, stack[i].name);
	}
	printf("\n");
}