/*
* ���� ������ ���ڿ��� ������ ��ȯ�ϴ� �Լ��� �����ϰ� ����� �˾ƺ��� ���α׷�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int myatoi(const char* str);	// myatoi

int main(void) {
	char str[16];
	printf("���� �ϳ��� �Է��Ͻÿ� >> ");
	scanf("%s", str);
	printf("�Լ� atoi<>�� �̿��� ���� -> %d\n", atoi(str));	// atoi ���
	printf("�Լ� myatoi<>�� �̿��� ���� -> %d\n", myatoi(str));	// myatoi ���
	return 0;
}

int myatoi(const char* str) {
	int n = strlen(str);	// ���ڿ� ���� ����
	int sum = 0;
	for (int i = 0; str[i]; i++) {
		if (isdigit(str[i])) {	// ���ڰ� �����̸�
			// str[i] - 48 -> ����
			// pow(10, (n-i-1)) -> �ڸ��� ���
			// n = 4, i = 0 -> 4�ڸ��� ���� ù��°, 1000�� �ڸ���
			sum += (str[i] - 48) * pow(10, (n-i-1));	// ���ڷ� �ٲٰ� 10�� �������� ���� �˸��� �ڸ����� �ٲ�
		}
	}
	return sum;
}