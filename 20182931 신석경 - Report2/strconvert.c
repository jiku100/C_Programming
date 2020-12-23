/*******************************************************
* ���ϸ�: strconvet.c
* ���α׷� ����: ���ڿ��� ���� 16������ 10������ �����Ͽ� ����ϴ� ���α׷�
*	16���� �˻� : isHex �Լ� ����
*   16���� 10������ ���� : convertDex �Լ� ����
*
*	�Է� : 0x, 0X�� �����ϰų� ���� ���� 16���� ���ڿ�
*
*   ���: �Էµ� 16���� ���ڿ��� 10������ �����Ͽ� ���
*
* ��¥: 2020�� 10�� 3��
* ����: 1.0
* �ۼ���: 20182931 �ż���
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int isHex(char* str); // 16 ���� ���� �˻��ϴ� �Լ�
int convertDex(char* str);	// 16 ���� ���ڿ��� 10 ���� ���ڷ� �ٲ㼭 ��ȯ�ϴ� �Լ�

int main(void) {
	printf("16������ ������ ��ȯ�ϴ� ���α׷��Դϴ�.\n");
	
	char str[32];

	while (1) {
		printf("16���� ���ڿ��� �Է��Ͻÿ� : ");
		scanf("%s", str);
		if (isHex(str) != 0) {		// 16������ �ƴϸ�
			printf(" ?? 16������ �ƴմϴ�.\n"); while (getchar() != '\n');	// ���� ��� �� ���� ����
			continue;
		}
		else {	// �������� 16���� �̸�
			printf(">> 10������ ��ȯ ��� : %d\n\n", convertDex(str));	// 10������ �ٲ㼭 ���
		}
	}
	return 0;	
}

int isHex(char* str) {
	int i = 0;
	if (str[0] == '0') {	// ù���ڰ� 0�� ��
		if (str[1] == 'x' || str[1] == 'X') {	// �ι�° ���ڰ� x, X�̸�
			i = 2;	// index 2���� �˻�
		}
	}

	char temp;
	for (i; i < strlen(str); i++) {
		temp = str[i];	// �� ���ڸ��� �˻�
		if (!isxdigit(temp))
			return -1;	// �Էµ� ���ڰ� 16������ �ƴϸ� return -1
		// isxdigit()�� �Էµ� ���ڰ� 16������ �ش��ϴ� �������� Ȯ��, �������� ��� isxdigit(temp) == 0	
	}

	return 0; // ������ ��� return 0;
}

int convertDex(char* str) {
	// strtol�� �Էµ� ���ڿ��� ����° argument�� �Էµ� ���ڿ� �ش��ϴ� ������ ���� long type���� �ٲ��ش�.
	// �ι�° argument�� ���� ���ڿ��� ������ ���, ��ȯ�� �Ϸ�� �� ���ڿ��� �ּҸ� ����ϱ� ���� pointer�� ����.
	return strtol(str, NULL, 16);	
}