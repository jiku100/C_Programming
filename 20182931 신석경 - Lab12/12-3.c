#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
#include <stdarg.h>

void vstrcat(char* str, ...);  // �������ڸ� ������ ���ڿ�  ���� �Լ�

int main(void) {
	char str[50] = { NULL };
	char* words[] = { "C", " programming", " course", " in", " Chung", " Ang", " University" };
	vstrcat(str, 1, words[0]);	// ���� ���� ������ �׿� �ش��ϴ� ������ ���ڿ� ����
	printf("%s\n", str);
	vstrcat(str, 2, words[1], words[2]);
	printf("%s\n", str);
	vstrcat(str, 1, words[3]);
	printf("%s\n", str);
	vstrcat(str, 3, words[4], words[5], words[6]);
	printf("%s\n", str);
	return 0;
}

void vstrcat(char* str, ...) {
	va_list argp;

	va_start(argp, str);
	int count = va_arg(argp, int);	// ���� ���� ������ �˱� ���ؼ� ���� ���� ������ ��������� ��
	for (int i = 0; i < count; i++) {
		strcat(str, va_arg(argp, char*));
	}
	va_end(argp);
}