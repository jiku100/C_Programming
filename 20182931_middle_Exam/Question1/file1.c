#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(void) {
	char str[64];
	char* token[64];
	char des[] = " \t";
	int sum = 0;	// ��� �� ����
	int num1 = 0;	// �ǿ����� 1
	int num2 = 0;	// �ǿ����� 2
	int isright = 1;	// �ùٸ� ������ �˻��ϴ� ����
	while (1) {
		printf("������� �Է��Ͻÿ� >> ");
		fgets(str, 64, stdin);	// fgets�� ������ �о��
		str[strlen(str) - 1] = '\0';	// ������ \n�� \0���� �ٲ�
		printf("%s", str);
		char* ptr = strtok(str, des);	// des�� �ִ� �����ڷ� ù ��ū �и�
		int i = 0;
		while (ptr != NULL) {	// �и��� ���� ������
			token[i] = ptr;	// token[i]�� ����
			ptr = strtok(NULL, des);	// �� �������� ��ū �и�
			i++;
		}
		token[i] = '\0';	// ��ū �и� �������� NULL���� �߰�
		
		i = 0;
		while (token[i]) {	// NULL���� ������
			if (isdigit(token[i][0])) {	// ��ū�� ù���ڰ� �����̸�, �� ������ 1��°�� ����
				// �� ������ �����ڰ� �Էµ� ���ĺ��ʹ� ������ ���ο��� ���� ���ڸ� �������� ������
				// ���ڴ� ������ if������ �� ó���ȴ�.
				num1 = atoi(token[i]);	// �� ��ū�� ���ڷ� ����
			}
			else if (strcmp(token[i], "+") == 0) {	// ���� + �̸�
				i++;	// ���� ���ڷ� �̵�
				if (isdigit(token[i][0])) {	// �� ���� ���ڰ� �����̸�
					num2 = atoi(token[i]);	// ���� �ٲ㼭
					num1 += num2;	// ����
				}
				else {	// �ƴϸ� ����
					printf(" �߸��� �����Դϴ�.\n\n");
					isright = 0;
					break;
				}
			}
			// �������� ���� ���
			else if (strcmp(token[i], "-") == 0) {
				i++;
				if (isdigit(token[i][0])) {
					num2 = atoi(token[i]);
					num1 -= num2;
				}
				else { 
					printf(" �߸��� �����Դϴ�.\n\n");
					isright = 0;
					break;
				}
			}
			else if (strcmp(token[i], "*") == 0) {
				i++;
				if (isdigit(token[i][0])) {
					num2 = atoi(token[i]);
					num1 *= num2;
				}
				else {
					printf(" �߸��� �����Դϴ�.\n\n");
					isright = 0;
					break;
				}
			}
			else if (strcmp(token[i], "/") == 0) {
				i++;
				if (isdigit(token[i][0]) && atoi(token[i]) != 0) {	// ���� ���ڰ� �����ε� 0�� �ƴ� ���
					num2 = atoi(token[i]);
					num1 /= num2;
				}
				else {
					printf(" �߸��� �����Դϴ�.\n\n");
					isright = 0;
					break;
				}
			}
			else {
				printf(" �߸��� �����Դϴ�.\n\n");
				isright = 0;
				break;
			}
			i++;	// ���� ���� �̵�
		}
		if (isright == 1) {	// �ùٸ� �����̸�
			sum = num1;	// num1�� ���
			printf(" = %d\n\n", sum);	// ��� ���
		}
		isright = 1;	// �ʱ�ȭ
		sum = num1 = num2 = 0;	// �ʱ�ȭ
	}
	return 0;
}