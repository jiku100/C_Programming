#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct student {
	int order;
	char name[16];
	float score1;
	float score2;
	float sum;
};
typedef struct student student;


void calSum(student* st) {
	float temp;
	for (int i = 0; i < 3; i++) {
		st[i].sum = (st[i].score1 + st[i].score2);
	}
}
int main(void) {
	FILE* f;
	char line[80];
	student st[3];
	if ((f = fopen("input.txt", "r")) == NULL) {
		fprintf(stdout, "파일 읽기 실패!!\n");
		exit(1);
	}

	fprintf(stdout, "input.txt 파일을 읽어 각 학생 점수의 합을 구하여 출력합니다.\n");
	fprintf(stdout, "---------------------------------------------------------\n\n");

	int cnt = 0;
	while (!feof(f)) {
		fgets(line, 80, f);
		sscanf(line, "%d %s    %f    %f", &st[cnt].order, st[cnt].name, &st[cnt].score1, &st[cnt].score2);
		cnt++;
	}

	calSum(st);

	fprintf(stdout, "%12s%8s%8s%8s\n", "이름", "점수1", "점수2", "합계");
	for (int i = 0; i < 3; i++) {
		fprintf(stdout, "%4d%8s%8.1f%8.1f%8.1f\n", st[i].order, st[i].name, st[i].score1, st[i].score2, st[i].sum);
	}

	fclose(f);
	return 0;
}