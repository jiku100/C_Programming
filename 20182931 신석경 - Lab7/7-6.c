/*
* 5�� �������� ���� ������ �Լ� myatoi()�� �̿��Ͽ� ����࿡ �Էµ� �� ������ ���� 
* ����� ����ϴ� ���α׷�
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int myatoi(const char* str);	// myatoi

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("������ ���� ���� ���ϰ� �ΰ��� ������ �Է��Ͻÿ�.\n");
		printf("C:\> �������� 100 200\n");
		return 0;
	}
	else {
		int num1 = myatoi(argv[1]);	// ù��° ���� ���ڷ� ����
		int num2 = myatoi(argv[2]);	// �ι�° ���� ���ڷ� ����

		int sum = num1 + num2;

		printf("\n�Է��� �� ���� ���� ��� : %d + %d = %d\n\n", num1, num2, sum);
	}
	return 0;
}

int myatoi(const char* str) {
	int n = strlen(str);	// ���ڿ� ���� ����
	int sum = 0;
	for (int i = 0; str[i]; i++) {
		if (isdigit(str[i])) {	// ���ڰ� �����̸�	
			sum += (str[i] - 48) * pow(10, (n - i - 1));	// ���ڷ� �ٲٰ� 10�� �������� ���� �˸��� �ڸ����� �ٲ�
		}
	}
	return sum;
}