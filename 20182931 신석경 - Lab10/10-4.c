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
		{"�迵��", "9952203", 4.2, "���ڰ��а�", "������"},
		{"���̿�", "9952123", 3.5, "���ڰ��а�", "ȸ���"},
		{"������", "9952108", 4.0, "���ڰ��а�", "���ΰ��̸�"},
		{"�ں���", "9952115", 3.0, "����Ʈ�����к�", "��������"},
		{"������", "0052033", 3.7, "����Ʈ�����к�", "����"}
	};
	char input[32];

	printf("  �� ��    �� ��      �� ��         �� ��            ����\n");
	printf("---------------------------------------------------------\n");
	for (int i = 0; i < 5; i++) {
		printf(" %s   %s      %d    %14s     %10s\n", students[i].name, students[i].Id, students[i].rate, students[i].major, students[i].course);
	}

	while (1) {
		printf("\n�˻��Ϸ��� �а��� �Է��Ͻÿ� >> ");
		scanf("%s", input);

		printf("\n  �� ��    �� ��      �� ��         �� ��            ����\n");
		printf("---------------------------------------------------------\n");
		for (int i = 0; i < 5; i++) {
			if (strcmp(students[i].major, input) == 0) {
				printf(" %s   %s      %d    %14s     %10s\n", students[i].name, students[i].Id, students[i].rate, students[i].major, students[i].course);
			}
		}
	}
	

	return 0;
}