#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
	FILE* f1, *f2;

	if ((f1 = fopen("sample.c", "r")) == NULL) {
		fprintf(stdout, "���� �б� ����!!\n");
		exit(1);
	}
	if ((f2 = fopen("chgsample.txt", "w+")) == NULL) {
		fprintf(stdout, "���� �б� ����!!\n");
		exit(1);
	}

	fprintf(stdout, "sample.c ���� ���� ���� ���: --> \n\n");

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
	fprintf(stdout, "\nchgsample.txt ���� ���� ���� ���: --> \n\n");

	while (!feof(f2)) {
		temp = fgetc(f2);
		fprintf(stdout, "%c", temp);
	}

	fclose(f1);
	fclose(f2);
	return 0;
}