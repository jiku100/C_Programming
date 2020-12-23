#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
	FILE* f1, *f2;

	if ((f1 = fopen("sample.c", "r")) == NULL) {
		fprintf(stdout, "파일 읽기 실패!!\n");
		exit(1);
	}
	if ((f2 = fopen("chgsample.txt", "w+")) == NULL) {
		fprintf(stdout, "파일 읽기 실패!!\n");
		exit(1);
	}

	fprintf(stdout, "sample.c 원본 파일 내용 출력: --> \n\n");

	int temp;
	while (!feof(f1)) {
		temp = fgetc(f1);
		fprintf(stdout, "%c", temp);
		
		if (isalpha(temp))
			if (islower(temp))
				temp = toupper(temp);
			else if (isupper(temp))
				temp = tolower(temp);
		fputc(temp, f2);
	}

	rewind(f2);
	fprintf(stdout, "\nchgsample.txt 변경 파일 내용 출력: --> \n\n");

	while (!feof(f2)) {
		temp = fgetc(f2);
		fprintf(stdout, "%c", temp);
	}

	fclose(f1);
	fclose(f2);
	return 0;
}