/*
* �ʵ�!!!!!
* sample1.c�� ���๮�ڰ� �ϳ� �� �־� �ٸ��� �νĵ˴ϴ�.
* �׷��� ������ ������ �� ������ �����Ͽ� ���๮�� �ϳ��� ���� �����Ͽ����ϴ�.
* ���� �ٶ��ϴ�.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
	FILE* f1;
	FILE* f2;

	if (argc < 3) {
		printf("������ ���� ���� 2���� �ʿ��մϴ�.\n");
		exit(1);
	}

	if ((f1 = fopen(argv[1], "r")) == NULL) {
		fprintf(stdout, "���� �б� ����!!\n");
		exit(1);
	}
	if ((f2 = fopen(argv[2], "r")) == NULL) {
		fprintf(stdout, "���� �б� ����!!\n");
		exit(1);
	}

	char f1_line[80];
	char f2_line[80];
	int isRight = 1;

	while (!feof(f1) && !feof(f2)) {
		fgets(f1_line, 80, f1);
		fgets(f2_line, 80, f2);

		if (strcmp(f1_line, f2_line) != 0) {
			isRight = 0;
			break;
		}
	}

	if (!feof(f1) || !feof(f2))
		isRight = 0;

	if (isRight == 0) {
		printf("%s�� %s�� ������ �ٸ� �����Դϴ�.\n", argv[1], argv[2]);
	}
	else {
		printf("%s�� %s�� ������ ���� �����Դϴ�.\n", argv[1], argv[2]);
	}

	fclose(f1);
	fclose(f2);
	return 0;
}