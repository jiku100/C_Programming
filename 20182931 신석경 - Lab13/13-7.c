#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
	FILE* f;

	if (argc < 2) {
		printf("�Էµ� ������ �����ϴ�.\n");
		exit(1);
	}
	if ((f = fopen(argv[1], "r")) == NULL) {
		fprintf(stdout, "�Էµ� ������ �����ϴ�.\n");
		exit(1);
	}
	fseek(f, 0, SEEK_END);
	printf("%s ���� ũ��: %d����Ʈ\n", argv[1], ftell(f));
	fclose(f);
}