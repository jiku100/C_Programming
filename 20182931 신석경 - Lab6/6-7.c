/*
* ������ �빮��, �ҹ���, ����, �׿� ���ڸ� 10�� �Է� �޾� �迭�� �����ϰ�,
* ������ �� ������ ��� �ϴ� ���α׷�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int mystrlen(char* str);
void checkToken(char* str);

int main(void) {
	char str[11];

	while (1) {
		printf("������ ���� 10���� �������� �Է��Ͻÿ� >> ");
		scanf("%s", str);
		checkToken(str);	// ��ū ���� ���
	}
	return 0;
}


int mystrlen(char* str) {	// ���ڿ� ���� ��ȯ �Լ�
	int n;
	for (n = 0; str[n]; n++);	// str[n]�� '\n' Ȥ�� NULL�� ���� �� ����
	return n;
}

void checkToken(char* str) {
	int n = mystrlen(str);	// ���ڿ� ���� ���� ����

	int num[] = { 0,0,0,0 };	// ���� ����, �ҹ���, �빮��, Ư������ ������ ��Ÿ��.

	for (int i = 0; i < n; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')	num[0]++;	// �빮�� -> 0�� index 1 ����
		else if (str[i] >= 'a' && str[i] <= 'z')	num[1]++;	// �ҹ��� -> 1�� index 1 ����
		else if (str[i] >= '0' && str[i] <= '9') num[2]++;	// ���� -> 2�� index 1 ����
		else	num[3]++;	// Ư�������� ��� 3�� index 1 ����
	}

	printf("�빮�� %d��, �ҹ��� %d��, ���� %d��, �׿� ���� %d�� �Դϴ�.\n\n", num[0], num[1], num[2], num[3]);
}