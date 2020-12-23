#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
	FILE* f;

	if (argc < 2) {
		printf("입력된 파일이 없습니다.\n");
		exit(1);
	}
	if ((f = fopen(argv[1], "r")) == NULL) {
		fprintf(stdout, "입력된 파일이 없습니다.\n");
		exit(1);
	}
	fseek(f, 0, SEEK_END);
	printf("%s 파일 크기: %d바이트\n", argv[1], ftell(f));
	fclose(f);
}