#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectionSort(char* str[], int arysize);
void printAry(char* str[], int arysize);

int main(void) {
	char* str[] = { "pascal","java","Ada","Python","C#","C++","C","Ruby","basic","Lisp" };
	int arysize = sizeof(str) / sizeof(char*);
	printf("���� ����<Selection Sorting> ....\n");
	printf("���� �� ����\n");
	printAry(str, arysize);
	selectionSort(str, arysize);
	printf("\n���� �� ����\n");
	printAry(str, arysize);
	return 0;
}

void selectionSort(char* str[], int arysize) {	//���� ���� ��� ���ڿ� ���� �Լ�
	for (int i = 0; i < arysize - 1; i++) {	// ������ �� ���ұ��� �˻�
		int min = i;	// �ּҸ� i�� ����
		for (int j = i + 1; j < arysize; j++) {	// i+1 ���� ������ ���ұ��� �˻�
			if(strcmp(str[j], str[min]) < 0) {	// strcmp(a, b)�� ����� ������� ���� ���������� a�� b�� �տ� �ִٴ� ��
				min = j;	// ���� j�� min�� ��
			}
		}
		// ������� �ּҰ� �Ǵ� ���� ã�� ���� i�� min�� �ٲٴ� ������ ���İ���
		char* temp = str[i];	// ���� i�� min�� char*�� �ٲ㼭 ���ڿ��� �����Ѵ�.
		str[i] = str[min];
		str[min] = temp;
	}
}

void printAry(char* str[], int arysize) {	// ���ڿ� �迭�� ����ϴ� �Լ�
	for (int i = 0; i < arysize; i++) {
		printf("%s ", str[i]);
	}
	printf("\n");
}