/*
* �־��� �������κ��� �ܾ �����Ͽ� �迭�� �����ϰ�, �迭�� ����� �ܾ ����ϴ� ���α׷�
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[] = "C and C++ languages are good!, Java and python languages are best?";
	char des[] = " ,!?";
	char* token[64];	// ��ū�� ������ ������ �迭

	printf("���ڿ��� �����ڸ� �̿��Ͽ� ��ū ����...\n");
	printf(" ���ڿ� : \"%s\"\n", str);
	printf(" ������ : \"%s\"\n", des);

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
		printf("%s\n", token[i]);	// ��ū ���
		i++;
	}
	return 0;
}