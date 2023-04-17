#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100
typedef enum {lparen, rparen, plus, minus, divide, times, mod, eos, operand} precedence;

int top = -1;
int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];

precedence getToken(char* symbol, int* n);
int eval();
void push(int op);
int pop();

int main() {
	int i = 0;
	FILE* fp = fopen("input.txt", "r");
	FILE* ofp = fopen("output.txt", "w");
	
	fscanf(fp, "%s", expr);
	printf("postfix expression : %s\n", expr);
	
	int res = eval();
	printf("the evaluation value : %d\n", res);
	fprintf(ofp, "postfix expression : %s\n", expr);
	fprintf(ofp, "the evaluation value : %d\n", res);

	fclose(fp), fclose(ofp);
}

int eval() {
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0; //counter
	top = -1;
	token = getToken(&symbol, &n);
	while (token != eos) {
		if (token == operand)
			push(symbol - '0');
		else {
			op2 = pop();
			op1 = pop();
			switch (token)
			{
			case plus: push(op1 + op2);
				break;
			case minus: push(op1 - op2);
				break;
			case times: push(op1 * op2);
				break;
			case mod: push(op1 % op2);
				break;
			case divide: push(op1 / op2);
			}
		}
		token = getToken(&symbol, &n);
	}
	return pop();
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

void push(int op) {
	if (top == MAX_STACK_SIZE - 1) {
		printf("stackfull\n");
	}
	else
		stack[++top] = op;
}

int pop() {
	if (top == -1) {
		printf("stackEmpty\n");
	}
	else
		return stack[top--];
}