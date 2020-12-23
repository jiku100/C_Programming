#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct date {
	int year;
	int month;
	int day;
};
struct movie {
	char moivename[32];
	int view;
	char director[32];
	struct date date;
};


int main(void) {
	struct movie m1 = { "명량", 17613000, "김한민", {2020, 7, 30} };
	struct movie m2 = { "도둑들", 12983000, "최동훈", {2020, 12, 17} };
	struct movie m3 = { "국제시장", 14257000, "윤제균", {2020, 12, 27} };

	int n;
	char name[32];

	printf("\t제목    감독    관객수     개봉일\n");
	printf("===============================================\n");
	printf("1. [%8s]  %s   %d     %d.%d.%d\n", m1.moivename, m1.director, m1.view, m1.date.year, m1.date.month, m1.date.day);
	printf("2. [%8s]  %s   %d     %d.%d.%d\n", m2.moivename, m2.director, m2.view, m2.date.year, m2.date.month, m2.date.day);
	printf("3. [%8s]  %s   %d     %d.%d.%d\n", m3.moivename, m3.director, m3.view, m3.date.year, m3.date.month, m3.date.day);
	printf("===============================================\n\n");

	printf("영화 감독을 수정합니다. <영화번호 감독이름> >> ");
	scanf("%d %s", &n, name);
	if (n == 1) {
		strcpy(m1.director, name);
	}
	else if (n == 2) {
		strcpy(m2.director, name);
	}
	else {
		strcpy(m3.director, name);
	}

	printf("\n\n\t제목    감독    관객수     개봉일\n");
	printf("===============================================\n");
	printf("1. [%8s]  %s   %d     %d.%d.%d\n", m1.moivename, m1.director, m1.view, m1.date.year, m1.date.month, m1.date.day);
	printf("2. [%8s]  %s   %d     %d.%d.%d\n", m2.moivename, m2.director, m2.view, m2.date.year, m2.date.month, m2.date.day);
	printf("3. [%8s]  %s   %d     %d.%d.%d\n", m3.moivename, m3.director, m3.view, m3.date.year, m3.date.month, m3.date.day);
	printf("===============================================\n\n");
	return 0;
}