#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int classnum;
	int score;
}element;

typedef struct queue* queuepointer;
typedef struct queue {
	element data;
	queuepointer link;
};

queuepointer front[3] = { NULL };
queuepointer rear[3] = { NULL };

void print_node(stackpointer);
void addq(int, element);
element deleteq(int);

int main() {
	int i;
	element student;
	FILE* fp = fopen("input.txt", "r");
	//파일 읽으면서 번호에 맞는 탑에 넣기
	while (!feof(fp)) {
		fscanf(fp, "%d %d %d", &i, &student.classnum, &student.score);
		addq(i, student);
	}
	printf("과목번호, 학반, 성적\n");
	for (i = 0; i < 3; i++) {
		printf("**********************\n");
		print_node(i);
	}
}

void addq(int i, element item) {
	queuepointer temp = (queuepointer)malloc(sizeof(*temp));
	temp->data = item;
	temp->link = NULL;
	if (front[i]) {
		rear[i]->link = temp;
	}
	else {
		front[i] = temp;
	}
	rear[i] = temp;
}

element deleteq(int i) {
	element e;
	queuepointer temp = front[i];
	front[i] = temp->link;
	e = temp->data;
	free(temp);
	return e;
}
void print_node(int i) {
	queuepointer ptr = (queuepointer)malloc(sizeof(*ptr));
	for (ptr = front[i]; ptr; ptr = ptr->link) {
		printf("       %d    %d    %d\n", i, ptr->data.classnum, ptr->data.score);
	}
}