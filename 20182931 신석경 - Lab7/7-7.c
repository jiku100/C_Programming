/*
* �Լ��� ����� �����ϱ� ���Ͽ� ���� �Լ��� ����ϴ� ������ ���α׷�
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[] = "C Code & C++ code";
	char str1[20];
	char str2[] = "&+";
	char str3[] = "code";
	char ch = 'd';

	printf("������ ���� ���ڿ�\n");
	printf("str1 = %s\n", str);
	printf("str2 = %s\n", str2);
	printf("str3 = %s\n", str3);
	printf("ch = %c\n\n\n", ch);

	strcpy(str1, str);	// �� string ���� ������ str1�� �ʱ�ȭ
	// 'strlwr': The POSIX name for this item is deprecated.
	// Instead, use the ISO C and C++ conformant name: _strlwer.
	// ���� Error �޼����� ���� strlwr�� _strlwr�� ����ؼ� ���
	printf("strlwer<str1>\n   ��ȯ�� ���ڿ� : %s\n\n\n", _strlwr(str1));

	strcpy(str1, str);	// �� string ���� ������ str1�� �ʱ�ȭ
	printf("strpbrk<str1, str2>\n    ��ȯ�� ���ڿ� : %s\n\n\n", strpbrk(str1, str2));

	strcpy(str1, str);	// �� string ���� ������ str1�� �ʱ�ȭ
	printf("strstr<str1, str3>\n    ��ȯ�� ���ڿ� : %s\n\n\n", strstr(str1, str3));

	strcpy(str1, str);	// �� string ���� ������ str1�� �ʱ�ȭ
	printf("strchr<str1, ch>\n    ��ȯ�� ���ڿ� : %s\n\n\n", strchr(str1, ch));

	return 0;
}