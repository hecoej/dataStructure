#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int nfind(char*, char*);
int main() {
	char str[100], pat[100];
	printf("문자열을 입력하세요 : ");
	scanf("%s", str);

	printf("비교할 패턴을 입력하세요 : ");
	scanf("%s", pat);

	int n =	nfind(str, pat);
	if (n == -1) {
		printf("패턴이 없습니다.");
	}
	else
	{
		printf("문자열 %d 번째부터 패턴이 시작됨..", n);
	}

	return 0;
}

int nfind(char* str, char* pat) {

	int lasts, lastp, endmatch, j=0, i=0, start=0;
	lasts = strlen(str) - 1;
	lastp = strlen(pat) - 1;
	endmatch = lastp;

	for (i = 0; endmatch <= lasts; endmatch++, start++) {
		if (str[endmatch] == pat[lastp]) {
			for (j = 0, i = start; j < lastp && str[i] == pat[j]; i++, j++);
		if (lastp == j)
			return start; 
		}
	}
	return -1;
}