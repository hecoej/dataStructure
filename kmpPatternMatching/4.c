#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define max_str_size 100
#define max_pattern_size 100

int failure[max_pattern_size];
char str[max_str_size];
char pat[max_pattern_size];

// abcabcabaaabcabcabcabccabcabc
// abcabcabca

void fail(char*);
int pmatch(char*, char*);

int main() {
	
	printf("문자열을 입력하세요 : ");
	scanf("%s", str);
	printf("비교할 패턴을 입력하세요 : ");
	scanf("%s", pat);

	fail(pat);
	printf("pat의 위치 정보 값\n");
	for (int i = 0; i < strlen(pat); i++) {
		printf("failure[%d]=%4d\t", i, failure[i]);
	}
	printf("\n");

	int n = pmatch(str, pat);
	if (n == -1) {
		printf("패턴이 없습니다.");
	}
	else
		printf("문자열 %d번째부터 패턴이 시작됨..", n);
}

void fail(char* pat) {

	int n = strlen(pat);
	failure[0] = -1;
	int i, j;
	for (j = 1; j < n; j++) {
		i = failure[j-1];
		while (pat[j] != pat[i + 1] && i >= 0) {
			i = failure[i];
		}
		if (pat[j] == pat[i + 1]) {
			failure[j] = i+1;
		}
		else
			failure[j] = -1;
	}
}

int pmatch(char* str, char* pat) {
	int i = 0, j = 0;
	int lens = strlen(str);
	int lenp = strlen(pat);
	while (i < lens && j < lenp) {
		if (str[i] == pat[j]) {
			i++, j++;
		}
		else if (j == 0) i++;
		else j = failure[j - 1] + 1;
	}
	return ((j == lenp) ? (i - lenp) : -1);
}