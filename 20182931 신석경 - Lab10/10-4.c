#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct student {
	char name[16];
	char Id[16];
	int rate;
	char major[32];
	char course[32];
};

int main(void) {
	struct student students[5] = {
		{"김영국", "9952203", 4.2, "전자공학과", "공무원"},
		{"강미연", "9952123", 3.5, "전자공학과", "회사원"},
		{"송은혜", "9952108", 4.0, "전자공학과", "프로게이머"},
		{"박보현", "9952115", 3.0, "소프트웨어학부", "웹마스터"},
		{"최종욱", "0052033", 3.7, "소프트웨어학부", "군인"}
	};
	char input[32];

	printf("  이 름    학 번      학 점         학 과            진로\n");
	printf("---------------------------------------------------------\n");
	for (int i = 0; i < 5; i++) {
		printf(" %s   %s      %d    %14s     %10s\n", students[i].name, students[i].Id, students[i].rate, students[i].major, students[i].course);
	}

	while (1) {
		printf("\n검색하려는 학과를 입력하시오 >> ");
		scanf("%s", input);

		printf("\n  이 름    학 번      학 점         학 과            진로\n");
		printf("---------------------------------------------------------\n");
		for (int i = 0; i < 5; i++) {
			if (strcmp(students[i].major, input) == 0) {
				printf(" %s   %s      %d    %14s     %10s\n", students[i].name, students[i].Id, students[i].rate, students[i].major, students[i].course);
			}
		}
	}
	

	return 0;
}