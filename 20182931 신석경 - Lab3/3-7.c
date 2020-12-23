/*
* int�� ���� value�� ���� 16���� ���� �����ϰ� char*�� �����Ͽ� 
* ���� byte�� �ش��ϴ� ���ڸ� ����ϴ� ���α׷�
*/

#include <stdio.h>

int main(void) {
	printf("int ������ ����Ǿ� �ִ� 16������ ���ڷ� ���\n\n");

	int n = 0x2f24263f;	// ������ �� ����
	char* pc = (char*) &n;	// n�� ����Ű�� ���� char ������ ����

	printf("����    �ּҰ�\n");

	for (int i = 0; i < 4; i++) {
		char ch = *(pc + i);	// char �������̱⿡ pc + i�� 1����Ʈ�� �̵�
		printf("  %c    %p\n", ch, pc + i);
	}
	printf("\n");
	return 0;
}