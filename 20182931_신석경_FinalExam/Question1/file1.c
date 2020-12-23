#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int numerator;
	int denominator;
} fraction;		// ����ü ����

fraction* add(fraction* f1, fraction* f2);
fraction* sub(fraction* f1, fraction* f2);
fraction* mul(fraction* f1, fraction* f2);
fraction* divide(fraction* f1, fraction* f2);
// ������ ���� �Լ� ����
int main(void) {
	fraction* f1, *f2;	// ������ ����ü ���� ����
	fraction* result = NULL;	// ��� ����ü ����
	int input1, input2;
	char op;
	char line[1024];
	char* ptr = NULL;
	f1 = calloc(0, sizeof(fraction));	// ���� �Ҵ�
	f2 = calloc(0, sizeof(fraction));	// ���� �Ҵ�
	int fail = 0;
	int i = 0;
	do
	{
		printf("�м��� ������� �Է��Ͻÿ� >> ");
		fgets(line, 1024, stdin);	// ���ڽ� �Է� �޾�
		ptr = strtok(line, "\t ");	// ����� \t���� ��ū �и�
		i = 0;	// � ������ �������� ����
		while (ptr != NULL)
		{
			if (i == 0) {	// i == 0�̸� ù ��ū �ǹ� -> 1/2 �� ���� �м�
				sscanf(ptr, "%d/%d", &input1, &input2);
				f1->numerator = input1;	// f1�� ����
				f1->denominator = input2;
				i++;
			}
			else if (i == 1) {	// i == 1�̸� ������ �ǹ�
				if (strcmp(ptr, "+") == 0 || strcmp(ptr, "-") == 0 || strcmp(ptr, "*") == 0 || strcmp(ptr, "/") == 0) {
					op = *ptr;
					i++;
				}
				else {	// �ش�Ǵ� �����ڰ� �ƴ� ��� ���� ��� �� ���ư�
					printf("������ ����\n");
					fail = 1;
					break;
				}
			}
			else if (i == 2) {	// i == 2�� ��� 3��° ��ū �ǹ� -> 2/3 �� ���� �м�
				sscanf(ptr, "%d/%d", &input1, &input2);
				f2->numerator = input1;
				f2->denominator = input2;	// f2�� ����
				i++;
			}
			else {	// �� �ʰ��� ��� ����
				printf("�Է� �ʰ�\n");
				fail = 1;
				break;
			}
			ptr = strtok(NULL, "\t ");
		}
		if (!fail) {	// �������� �ʾ�����, �� �ùٸ� �м� �� ������ �Է��̸� ���� ���� ��� result�� ����
			if (op == '+') {
				result = add(f1, f2);
			}
			else if (op == '-') {
				result = sub(f1, f2);
			}
			else if (op == '*') {
				result = mul(f1, f2);
			}
			else if (op == '/') {
				result = divide(f1, f2);
			}

			printf(" = %d/%d\n", result->numerator, result->denominator);	// result�� �Ҵ�� �� ���
		}
		fail = 0;	// �ʱ�ȭ
		i = 0;		// �ʱ�ȭ
	} while (1);

	return 0;
}

fraction* add(fraction* f1, fraction* f2) {
	fraction* result = calloc(1, sizeof(fraction));

	result->numerator = f1->numerator * f2->denominator + f2->numerator * f1->denominator;
	result->denominator = f1->denominator * f2->denominator;
	return result;
}
fraction* sub(fraction* f1, fraction* f2) {
	fraction* result = calloc(1, sizeof(fraction));

	result->numerator = f1->numerator * f2->denominator - f2->numerator * f1->denominator;
	result->denominator = f1->denominator * f2->denominator;
	return result;
}
fraction* mul(fraction* f1, fraction* f2) {
	fraction* result = calloc(1, sizeof(fraction));

	result->numerator = f1->numerator * f2->numerator;
	result->denominator = f1->denominator * f2->denominator;
	return result;
}
fraction* divide(fraction* f1, fraction* f2) {
	fraction* result = calloc(1, sizeof(fraction));

	result->numerator = f1->numerator * f2->denominator;
	result->denominator = f1->denominator * f2->numerator;
	return result;
}