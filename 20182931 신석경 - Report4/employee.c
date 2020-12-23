/*******************************************************
* ���ϸ�: employee.c
* ���α׷� ����: ȸ�� ����� ������ �����ϴ� ���α׷�
*	����ü 1: ����� ��Ÿ���� person ����ü
*   ����ü 2: ����� ��Ÿ���� employee ����ü

*	��� ���: print() ����
*	���� ���: calYearMoney() ����
*
*	�Է� 1: ��� Ȥ�� �̸��� ���ο� �μ�Ƽ��
*
*	���: �� ������� ���, �̸�, ��ȭ��ȣ, ����, �μ�Ƽ��, ����
*
* ��¥: 2020�� 11�� 24��
* ����: 1.0
* �ۼ���: 20182931 �ż���
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct person {
	char name[16];	// �̸� ����
	char phonenumber[14];	// �ڵ��� ��ȣ ����
};

struct employee {
	char id[10];	// ��� ����
	int money;	// ����
	int raise;	// �μ�Ƽ��
	struct person p;	// ����� ���� ������ ������ ����
};

void print(struct employee* emp);	// ��� ���� ���
int calYearMoney(struct employee emp);	// ������ ����ϴ� �Լ�

int main(void) {
	struct employee employees[4] = {	// �ʱ� ��� ����
		{"20123478", 1200000, 120, {"������", "011-1111-1111"}},
		{"20123479", 1500000, 150, {"���ڰ�", "011-2222-2456"}},
		{"20123480", 1800000, 180, {"������", "011-3333-2456"}},
		{"20123481", 2200000, 250, {"���¿�", "017-2222-2456"}}
	};

	char target[20];	// �ٲ� ����� �̸� Ȥ�� ���
	int raise;			// �ٲ� �μ�Ƽ��

	while (1) {
		print(employees);	// ��� ����� ���� ���
		printf("\n�μ�Ƽ�긦 �����մϴ�...\n");
		printf("��� �Ǵ� �̸��� ���ο� �μ�Ƽ�긦 �Է��Ͻÿ� >> ");
		scanf("%s %d", target, &raise);	// ��� Ȥ�� �̸��� �μ�Ƽ�긦 �Է¹���

		for (int i = 0; i < 4; i++) {
			// �̸��� target�� ���ų�, ����� target�� ���� ���
			if (strcmp(employees[i].id, target) == 0 || strcmp(employees[i].p.name, target) == 0) {
				employees[i].raise = raise;	// �� ����� �μ�Ƽ�긦 �ٲ�
			}
		}
	}
	return 0;
}

void print(struct employee* emp) {
	printf("\n   ���   �� ��     ��ȭ��ȣ     ����    �μ�Ƽ��    ����\n");
	printf("------------------------------------------------------------\n");
	for (int i = 0; i < 4; i++) {
		// �� ����� ���, �̸�, ��ȭ��ȣ, ����, �μ�Ƽ��, ������ ���
		printf("%s  %s  %s  %d   %d%%   %d\n", emp[i].id, emp[i].p.name, emp[i].p.phonenumber, emp[i].money, emp[i].raise, calYearMoney(emp[i]));
	}
}

int calYearMoney(struct employee emp) {
	// ���� ���Ͽ����� int ���길 ����Ͽ� �����ϰ� ������.
	return emp.money * (12 + emp.raise / 100);
}