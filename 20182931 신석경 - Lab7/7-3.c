/*
* ǥ���Է����� ���� ���ڿ����� Ư�� ���ڸ� �����ϴ� �Լ� delchar()�� �����Ͻÿ�. 
* �׸��� �Լ� delchar()�� ȣ���Ͽ� �����ϰ� ����� ����ϴ� ���α׷�
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void delchar(char str[], const char ch);

int main(void) {
	char str[64];
	char ch;
	printf("���ڿ��� �Է��Ͻÿ� >> ");
	fgets(str, 64, stdin);
	printf("������ ���ڸ� �Է��Ͻÿ� >> ");
	scanf(" %c", &ch);
	delchar(str, ch);	// ���ڿ����� ch�� �ش��ϴ� ��� ���� ����
	printf("delchar<> ȣ�� ���� ���: %s\n", str);
	return 0;
}

void delchar(char str[], const char ch) {
	char* temp = NULL;	// ���� ��ġ �����ϱ� ���� ����
	while (*str != '\0') {	// null�� �ƴ� ���
		if (*str == ch) {	// ������ �����̸�
			temp = str;		// ������ ��ġ ����
			while (*str) {	// null ���� ������
				*str = *(str + 1);	// ���� ���ڸ� ������ ����
				str++;	// ���ڿ� ��ġ ����
			}
			str = temp;	// ������ ��ġ ����
		}
		else {	// �ƴϸ�
			str++;	// �� ���� ���ں��� �˻�
		}	
	}
}