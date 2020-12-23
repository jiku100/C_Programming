#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int check_num(char* str1, char* str2);
int check_op(char* str);

int main(int argc, char* argv[]) {
	if (argc < 4) {
		printf(" ?? �߸��� ������Դϴ�.\n\n");
		return 0;
	}
	else {
		int num1;
		int num2;
		int result;
		if (check_num(argv[1], argv[3]) == 0) {	// �־��� �Է��� �����̸�
			num1 = atoi(argv[1]); // ù��° ���� ���ڷ� ����
			num2 = atoi(argv[3]);	// �ι�° ���� ���ڷ� ����
		}
		else {
			printf(" ?? �ǿ����ڰ� ������ �ƴմϴ�.\n\n");
			return 0;	//���α׷� ����
		}
		
		if (check_op(argv[2]) == 0) {
			if (strcmp(argv[2], "+") == 0) {	// + �����̸�
				result = num1 + num2;
				printf("%d %s %d = %d\n\n", num1, argv[2], num2, result);
			}
			else if (strcmp(argv[2], "-") == 0) {	// - �����̸�
				result = num1 - num2;
				printf("%d %s %d = %d\n\n", num1, argv[2], num2, result);
			}
			else if (strcmp(argv[2], "*") == 0) {	// * �����̸�
				result = num1 * num2;
				printf("%d %s %d = %d\n\n", num1, argv[2], num2, result);
			}
			else if (strcmp(argv[2], "/") == 0) {	// / �����̸�
				if (num2 == 0) {	// �ڿ� �ǿ����ڰ� 0�̸�
					result = 0;	// ��� 0
				}
				else {
					result = num1 / num2;	// �ƴϸ� ����
				}
				printf("%d %s %d = %d\n\n", num1, argv[2], num2, result);
			}
		}
		else {
			printf(" ?? �߸��� �������Դϴ�.\n\n");
			return 0;
		}
	}
	return 0;
}

int check_num(char* str1, char* str2) {
	// str1�� ���ڷθ� �̷�����ִ��� Ȯ��
	int n = strlen(str1);
	for (int i = 0; i < n; i++) {
		if(!isdigit(str1[i]))
			return -1;
	}
	// str2�� ���ڷθ� �̷�����ִ��� Ȯ��
	n = strlen(str2);
	for (int i = 0; i < n; i++) {
		if (!isdigit(str2[i]))
			return -1;
	}
	return 0;
}

int check_op(char* str) {
	// ��Ģ ���� ������ ��� 0 return �ƴϸ� -1
	if (strcmp(str, "+") == 0);
	else if (strcmp(str, "-") == 0);
	else if (strcmp(str, "*") == 0);
	else if (strcmp(str, "/") == 0);
	else {
		return -1;
	}
	return 0;
}