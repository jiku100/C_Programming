#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char** argv) {
	FILE* f1;
	FILE* f2;

	if (argc < 3) {
		printf("복사할 원본 파일과 대상 파일이 없습니다.\n");
		exit(1);
	}
	if ((f1 = fopen(argv[1], "r")) == NULL) {
		fprintf(stdout, "복사할 원본 파일과 대상 파일이 없습니다.\n");
		exit(1);
	}
	if ((f2 = fopen(argv[2], "w")) == NULL) {
		fprintf(stdout, "복사할 원본 파일과 대상 파일이 없습니다.\n");
		exit(1);
	}

	char line[80];
	;
	while (!feof(f1)) {
		fgets(line, 80, f1);
		fputs(line, f2);
	}

	printf("%s 파일에서 %s 파일로 복사가 완료되었습니다.\n%s 파일을 열어 확인해 보시오.\n", argv[1], argv[2], argv[2]);
	fclose(f1);
	fclose(f2);
	return 0;
}