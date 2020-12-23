#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct person {
	char id[10];
	char name[16];
	char phonenumber[14];
};

struct employee {
	int money;
	int raise;
	struct person p;
};

void print(struct employee* emp);
int calYearMoney(struct employee emp);

int main(void) {
	struct employee employees[4] = {
		{1200000, 120, {"20123478", "김지혜", "011-1111-1111"}},
		{1500000, 150, {"20123479", "김자경", "011-2222-2456"}},
		{1800000, 180, {"20123480", "강동구", "011-3333-2456"}},
		{2200000, 250, {"20123481", "안태용", "017-2222-2456"}}
	};

	char target[20];
	int raise;

	while (1) {
		print(employees);
		printf("\n인센티브를 변경합니다...\n");
		printf("사번 또는 이름과 새로운 인센티브를 입력하시오 >> ");
		scanf("%s %d", target, &raise);

		for (int i = 0; i < 4; i++) {
			if (strcmp(employees[i].p.id, target) == 0 || strcmp(employees[i].p.name, target) == 0) {
				employees[i].raise = raise;
			}
		}
	}
	return 0;
}

void print(struct employee* emp) {
	printf("\n   사번   이 름     전화번호     월급    인센티브    연봉\n");
	printf("------------------------------------------------------------\n");
	for (int i = 0; i < 4; i++) {
		printf("%s  %s  %s  %d   %d%%   %d\n", emp[i].p.id, emp[i].p.name, emp[i].p.phonenumber, emp[i].money, emp[i].raise, calYearMoney(emp[i]));
	}
}

int calYearMoney(struct employee emp) {
	// 인센티브에 대해 소수점 계산까지 진행, word 파일에서는 int 연산만 함.
	return emp.money * (12 + emp.raise / 100.);
}