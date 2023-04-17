#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100
static int isp[] = { 0,19,12,12,13,13,13,0 };
static int icp[] = { 20,19,12,12,13,13,13,0 };
typedef enum { lparen, rparen, plus, minus, divide,
				times, mod, eos, operand } precedence;

int top = -1;
int npush = 0;
int npop = 0;

int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];

void postfix();
void printToken(precedence);
precedence getToken(char* symbol, int* n);
int pop();
void push(int);

int main() {
	FILE* fp = fopen("input.txt", "r");

	fscanf(fp, "%s", expr);
	printf("<<<<< infix to postfix >>>>>\n");
	printf("infix expression\t: %s\n", expr);

	printf("postfix expression\t: ");
	postfix();

	fclose(fp);
	return 0;
}
void postfix() {
	char symbol;
	precedence token;
	int n = 0;
	top = 0;
	stack[0] = eos;
	for (token = getToken(&symbol, &n); token != eos;
		token = getToken(&symbol, &n)) {
		if (token == operand) {
			printf("%c", symbol);
		}
		else if (token == rparen) {
			while (stack[top] != lparen) {
				printToken(pop());
			}
			pop();
		}
		else {
			while (isp[stack[top]] >= icp[token]) {
				printToken(pop());
			}
			push(token);
		}
	}
	while ((token = pop()) != eos) {
		printToken(token);
	}
	printf("\n");
}

precedence getToken(char* symbol, int* n) {
	*symbol = expr[(*n)++];
		switch (*symbol) {
		case '(': return lparen;
		case ')': return rparen;
		case '+': return plus;
		case '-': return minus;
		case '/': return divide;
		case '*': return times;
		case '%': return mod;
		case '\0': return eos;
		default: return operand;
		}
}

void printToken(precedence pre) {
	//char item;
	switch (pre)
	{
	case plus:	printf("%c", '+');
		 break;
	case minus:	printf("%c", '-');
		 break;
	case divide:	printf("%c", '/');
		 break;
	case times:	printf("%c", '*');
		 break;
	case mod:	printf("%c", '%');
		 break;
	default:;	// operand
	}
	//expr[idx++] = item;
}
void push(int op) {
	if (top >= MAX_STACK_SIZE - 1) {
		printf("stackFull\n");
		return;
	}
	stack[++top] = op;
}

int pop() {
	if (top == -1) {
		printf("stackEmpty\n");
		return 0;
	}
	return stack[top--];
}