#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* f;

	if ((f = fopen("sample.c", "r")) == NULL) {
		fprintf(stdout, "���� �б� ����!!\n");
		exit(1);
	}

	fprintf(stdout, "sample.c�� �о ������ �״�� ����մϴ�.\n");
	fprintf(stdout, "-----------------------------------------\n\n");
	int ch;
	while (!feof(f)) {
		ch = fgetc(f);
		fprintf(stdout, "%c", ch);
	}

	fclose(f);
	return 0;
}