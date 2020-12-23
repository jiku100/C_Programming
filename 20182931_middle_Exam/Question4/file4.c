#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int mystrlen(char* str);
int mystrcmp(char* str1, char* str2);
int mystrncmp(char* str2, char* str3, int n);
void mystrcpy(char* dest, char* str1);

int main(void) {
	char* str1 = "C Language";
	char* str2 = "C language";
	char* str3 = "C languages";
	char dst[64] = " ";
	printf("str1 = %s\n", str1);
	printf("str2 = %s\n", str2);
	printf("str3 = %s\n", str3);
	printf("dest = %s\n\n", dst);

	printf("strlen<str1> = %d\n", strlen(str1));
	printf("mystrlen<str1> = %d\n\n", mystrlen(str1));

	printf("strcmp<str1> = %d\n", strcmp(str1, str2));
	printf("mystrcmp<str1> = %d\n\n", mystrcmp(str1, str2));

	printf("strncmp<str2, str3, 10> = %d\n", strncmp(str2, str3, 10));
	printf("mystrncmp<str2, str3, 10> = %d\n\n", mystrncmp(str2, str3, 10));

	strcpy(dst, str1);
	printf("strcpy<dest, str1> = %s\n", dst);
	mystrcpy(dst, str1);
	printf("mystrcpy<dest, str1> = %s\n\n", dst);
	return 0;
}


int mystrlen(char* str) {
	int n;
	for (n = 0; str[n]; n++);	// str[n]�� '\n' Ȥ�� NULL�� ���� �� ����	n���� ������Ŵ
	return n;
}

int mystrcmp(char* str1, char* str2) {
	int result;
	while (*str1 && *str2) {	// str1�� str2�� NULL�� �ƴ� �� ����
		if (*str1 != *str2) {	// �� ���ڰ� �ٸ���
			break;
		}
		str1++;	// ���� ���� ��
		str2++;	// ���� ���� ��
	}
	result = *str1 - *str2; // �˻��� ���ڿ����� ��
	if (result < 0)	// ������ -1
		result = -1;
	else if (result > 0)	// ����� 1
		result = 1;
	
	return result;
}

int mystrncmp(char* str2, char* str3, int n) {
	int result;
	int i = 0;
	for (i; i < n; i++) {
		if (!str2[i] || !str3[i])	// �� �߿� �ƹ��ų� NULL�̶��
			break;
		else if (str2[i] != str2[i])	// ���� ���ڰ� �ٸ���
			break;

	}
	int n1 = strlen(str2);	// �� ���ڿ� ���� ����
	int n2 = strlen(str3);
	// for ���� ������ ���� �� ���� i�� ���ڿ� ���̿� ������ i ���� �˻��Ϸ����� ���� ���� index�� ����Ų��. �׷��Ƿ� 1�� ����.
	if (n1 == i) {
		i--;
	}
	else if (n2 == i) {
		i--;
	}
	result = str2[i] - str3[i]; // �˻��� ���ڿ����� ��, �̶� i�� for������ �����ϰ� ������ ������
	// �˻��� ���� ���� index�� ����Ű�Ƿ� 1�� ������Ѵ�.
	if (result < 0)	// ������ -1
		result = -1;
	else if (result > 0)	// ����� 1
		result = 1;

	return result;
}

void mystrcpy(char* dest, char* str1) {
	int index = 0;
	while (str1[index]) {
		dest[index] = str1[index];
		index++;
	}
	dest[index] = str1[index];	// NULL ���ڱ��� ����
}