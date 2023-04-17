#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int classnum;
	int score;
}element;

typedef struct stack* stackpointer;
typedef struct stack {
	element data;
	stackpointer link;
};

stackpointer top[3] = { NULL };

void print_node(stackpointer);
void push(int, element);
element pop(int);

int main() {
	int i;
	element student;
	FILE* fp = fopen("input.txt", "r");
	//파일 읽으면서 번호에 맞는 탑에 넣기
	while (!feof(fp)) {
		fscanf(fp, "%d %d %d", &i, &student.classnum, &student.score);
		push(i, student);
	}
	printf("과목번호, 학반, 성적\n");
	for (i = 0; i < 3; i++) {
		printf("**********************\n");
		print_node(i);
	}
}

void push(int i, element item) {
	stackpointer temp = (stackpointer)malloc(sizeof(*temp));
	temp->data = item;
	temp->link = top[i];
	top[i] = temp;
}

element pop(int i) {
	element e;
	stackpointer temp = top[i];
	e = temp->data;
	top[i] = temp->link;
	free(temp);
	return e;
}

void print_node(int i) {
	stackpointer ptr;
	for (ptr = top[i]; ptr; ptr = ptr->link) {
		printf("       %d    %d    %d\n", i, ptr->data.classnum, ptr->data.score);
	}
}