/*
* �� ���� ���ڿ��� ǥ���Է����� �Է� �޾� �������� �빮�ڴ� �ҹ��ڷ�, 
* �ҹ��ڴ� �빮�ڷ� ��ȯ�Ͽ� ����ϴ� ���α׷�
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[128];
	printf("���� ������ �Է��Ͻÿ�\n");
	fgets(str, 128, stdin);
	printf("\n�Է��� ���ڿ����� �빮�ڿ� �ҹ��ڸ� �ݴ�� ��ȯ...\n");

	for (int i = 0; str[i]; i++) {
		if (islower(str[i]))	// �ҹ����̸�
		{
			str[i] = toupper(str[i]);	// �빮�ڷ� �ٲ�
		}
		else if (isupper(str[i]))	// �빮���̸�
		{
			str[i] = tolower(str[i]);	// �ҹ��ڷ� �ٲ�
		}
	}
	printf("%s\n", str);
	return 0;
}
