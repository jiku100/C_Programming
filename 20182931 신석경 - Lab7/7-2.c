/*
* �� ���ڿ��� �� ���ڿ��� �����ϴ� �Լ� mystrcat()�� �����Ͽ� 
* ���̺귯�� �Լ� strcat() �� ����� ��
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void mystrcat(char s1[], const char s2[]);	// mystrcat

int main(void) {
	char s1[50] = "C ";
	char s2[50] = "C ";
	char* s3 = "programming language";
	

	printf("ù��° ���ڿ� : %s\n", s1);
	printf("�ι�° ���ڿ� : %s\n", s3);
	strcat(s1, s3);		// s1�� s3�� strcat ����
	mystrcat(s2, s3);	// s2�� s3�� mystrcat ����
	printf("���ڿ� ���� ���\n");
	printf("strcat<> : %s\n", s1);	// s1 ���
	printf("mystrcat<> : %s\n", s2);	// s2 ���
	return 0;
}

void mystrcat(char s1[], const char s2[]) {
	while (*s1)	// null ���ڱ��� s1 ������ ����
		s1++;
	// s1�� null���ں���
	while ((*s1++ = *s2++) != '\0');	// s2�� ���� s1���� ���� -> ������ ���� null�̸� ����
}