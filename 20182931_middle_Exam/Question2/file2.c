#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int recur_strlen(char* str, int index);

int main(void) {
	char str[64];
	while (1) {
		printf("Enter a string: ");
		fgets(str, 64, stdin);	// fgets�� ������ �о��
		printf("Total number of characters <string length> are %d\n\n", recur_strlen(str,0));	// ��� ���
	}
	return 0;
}

int recur_strlen(char* str, int index) {
	if (str[index] && str[index] != '\n') {	// �Էµ� str�� index �� ���ڰ� NULL�� �ƴϰ�, ���๮�ڰ� �ƴϸ�
		return 1 + recur_strlen(str, index + 1);	// �� ���� ���ڸ� �˻��� �Լ��� + 1 �� return
	}
	else {
		return 0;	// NULL Ȥ�� \n�̸� 0 ����
	}
}