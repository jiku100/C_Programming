/*
* 필독!!!!!
* sample1.c에 개행문자가 하나 더 있어 다르게 인식됩니다.
* 그래서 과제를 진행할 때 파일을 수정하여 개행문자 하나를 지워 진행하였습니다.
* 참고 바랍니다.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
	FILE* f1;
	FILE* f2;

	if (argc < 3) {
		printf("내용을 비교할 파일 2개가 필요합니다.\n");
		exit(1);
	}

	if ((f1 = fopen(argv[1], "r")) == NULL) {
		fprintf(stdout, "파일 읽기 실패!!\n");
		exit(1);
	}
	if ((f2 = fopen(argv[2], "r")) == NULL) {
		fprintf(stdout, "파일 읽기 실패!!\n");
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
		printf("%s와 %s는 내용이 다른 파일입니다.\n", argv[1], argv[2]);
	}
	else {
		printf("%s와 %s는 내용이 같은 파일입니다.\n", argv[1], argv[2]);
	}

	fclose(f1);
	fclose(f2);
	return 0;
}