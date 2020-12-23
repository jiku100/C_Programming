/*******************************************************
* ���ϸ�: password.c
* ���α׷� ����: ��ȣ�� �Է¹ް�, ��ȣ�� �������� �˻��ϴ� ���α׷�
*	������ �˻� : isSafe �Լ� ����
*	���ڿ� ���ϼ� �˻� : isSameStr �Լ� ����
*	���ڿ� ���� : mystrlen �Լ� ����
*
*	�Է� : ��й�ȣ ���ڿ�
*
*   ���1: �������� �������� ���� ��� �� ���� ���
*	���2: �������� ��Ȯ�� ��� ��й�ȣ ���Է��϶�� ���� ���
*	���3: ���Է��� ��й�ȣ�� ������ ��� ��й�ȣ ���� ��� �� ����
*
* ��¥: 2020�� 10�� 3��
* ����: 1.0
* �ۼ���: 20182931 �ż���
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int mystrlen(char* str);	// ���ڿ� ���� ��ȯ �Լ�
int isSafe(char* password);	// ������ �˻� �Լ�
int isSameStr(char* password, char* check);	// ���ڿ� ���ϼ� Ȯ�� �Լ�

int main(void) {

	char password[16];	// ��й�ȣ
	
	do
	{
		printf("��й�ȣ�� �����Ͻÿ� : ");
		scanf("%s", password);
	} while (isSafe(password) != 0);	// ���ռ� �˻簡 �������� ���

	char check[16];	// ��й�ȣ üũ��

	do
	{
		printf("��й�ȣ�� ���Է��Ͻÿ� : ");
		scanf("%s", check);
	} while (isSafe(check) != 0 || isSameStr(password, check) != 0);// ���ռ� �˻�, ���ڿ� ��ġ �˻簡 �������� ���

	printf("��й�ȣ�� ���������� ����������ϴ�.\n\n");
	return 0;
}

int mystrlen(char* str) {
	int n;
	for (n = 0; str[n]; n++);	// str[n]�� '\n' Ȥ�� NULL�� ���� �� ����
	return n;
}

int isSafe(char* password) {
	int n = mystrlen(password);	// ���ڿ� ���� ���� ����

	int conditions[] = { 0,0,0,0 };	// ���� ����, �ҹ���, �빮��, Ư������ ������ ��Ÿ��.

	for (int i = 0; i < n; i++) {
		if (password[i] >= '0' && password[i] <= '9') conditions[0]++;	// ���ڸ� 0�� index 1 ����
		else if (password[i] >= 'a' && password[i] <= 'z')	conditions[1]++;	// �ҹ��� -> 1�� index 1 ����
		else if (password[i] >= 'A' && password[i] <= 'Z')	conditions[2]++;	// �빮�� -> 2�� index 1 ����
		else	conditions[3]++;	// Ư�������� ��� 3�� index 1 ����
	}

	int checkSafe = 0;

	for (int i = 0; i < 4; i++) {
		if (conditions[i] > 0)	checkSafe++;	// ������ ���Ǹ��� 1�� �̻��� ���� ��� cheackSafe 1 ����
	}

	if (n < 8) {		// ���� ���� 8�� �̸�
		printf(" >> ��й�ȣ�� 8�� �̻��̾�� �մϴ�.\n");
		return -1;
	}
	else if (n > 12) {	// ���� ���� 12�� �ʰ�
		printf(" >> ��й�ȣ�� 12�� ���Ͽ��� �մϴ�.\n");
		return -1;
	}
	else if (checkSafe < 3) {	// ��й�ȣ�� �빮��, �ҹ���, ����, Ư������ �� 3���� �̸��� �����ϴ� ���
		printf(" >> ��й�ȣ�� ����, �ҹ���, �빮��, Ư������ �� 3���� �̻��� ���ԵǾ�� �մϴ�.\n");
		return -1;
	}	
	return 0;
}

int isSameStr(char* password, char* check) {
	int p_len = mystrlen(password);	// password ����
	int c_len = mystrlen(check);	// ���Է� ���ڿ� ����

	if (p_len != c_len) {	// ���ڿ� ���̰� �ٸ���
		printf("��й�ȣ�� ���� �ٸ��ϴ�.\n");
		return -1;
	}

	for (int i = 0; i < p_len; i++) {
		if (password[i] != check[i]) {		// �� ���ڰ� �ٸ���
			printf("��й�ȣ�� ���� �ٸ��ϴ�.\n");
			return -1;
		}
	}
	return 0;
}