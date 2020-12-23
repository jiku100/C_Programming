#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* f;

	if ((f = fopen("sample.c", "r")) == NULL) {
		fprintf(stdout, "파일 읽기 실패!!\n");
		exit(1);
	}

	fprintf(stdout, "sample.c를 읽어서 내용을 그대로 출력합니다.\n");
	fprintf(stdout, "-----------------------------------------\n\n");
	int ch;
	while (!feof(f)) {
		ch = fgetc(f);
		fprintf(stdout, "%c", ch);
	}

	fclose(f);
	return 0;
}