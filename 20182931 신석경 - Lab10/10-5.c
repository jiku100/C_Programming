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
		{1200000, 120, {"20123478", "������", "011-1111-1111"}},
		{1500000, 150, {"20123479", "���ڰ�", "011-2222-2456"}},
		{1800000, 180, {"20123480", "������", "011-3333-2456"}},
		{2200000, 250, {"20123481", "���¿�", "017-2222-2456"}}
	};

	char target[20];
	int raise;

	while (1) {
		print(employees);
		printf("\n�μ�Ƽ�긦 �����մϴ�...\n");
		printf("��� �Ǵ� �̸��� ���ο� �μ�Ƽ�긦 �Է��Ͻÿ� >> ");
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
	printf("\n   ���   �� ��     ��ȭ��ȣ     ����    �μ�Ƽ��    ����\n");
	printf("------------------------------------------------------------\n");
	for (int i = 0; i < 4; i++) {
		printf("%s  %s  %s  %d   %d%%   %d\n", emp[i].p.id, emp[i].p.name, emp[i].p.phonenumber, emp[i].money, emp[i].raise, calYearMoney(emp[i]));
	}
}

int calYearMoney(struct employee emp) {
	// �μ�Ƽ�꿡 ���� �Ҽ��� ������ ����, word ���Ͽ����� int ���길 ��.
	return emp.money * (12 + emp.raise / 100.);
}