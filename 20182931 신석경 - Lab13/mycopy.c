#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char** argv) {
	FILE* f1;
	FILE* f2;

	if (argc < 3) {
		printf("������ ���� ���ϰ� ��� ������ �����ϴ�.\n");
		exit(1);
	}
	if ((f1 = fopen(argv[1], "r")) == NULL) {
		fprintf(stdout, "������ ���� ���ϰ� ��� ������ �����ϴ�.\n");
		exit(1);
	}
	if ((f2 = fopen(argv[2], "w")) == NULL) {
		fprintf(stdout, "������ ���� ���ϰ� ��� ������ �����ϴ�.\n");
		exit(1);
	}

	char line[80];
	;
	while (!feof(f1)) {
		fgets(line, 80, f1);
		fputs(line, f2);
	}

	printf("%s ���Ͽ��� %s ���Ϸ� ���簡 �Ϸ�Ǿ����ϴ�.\n%s ������ ���� Ȯ���� ���ÿ�.\n", argv[1], argv[2], argv[2]);
	fclose(f1);
	fclose(f2);
	return 0;
}