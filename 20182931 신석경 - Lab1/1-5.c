#include <stdio.h>

/*
* getchar�� �Է� �޾� putchar�� ���, printf�� 8����, 10����, 16���� ����ϴ� ���α׷�
*/

int main(void) {
	printf("���ڸ� �Է¹޾� ����, 8����, 10����, 16������ ���\n\n");
	printf("���ڸ� �Է��ϼ���: ");

	char input = getchar();		// getchar�� �Էµ� ���ڸ� input�� ����

	printf("�Էµ� ���ڴ�: "); putchar(input); putchar('\n\n');	// �Էµ� ���ڸ� putchar�� ����� ���ڷ� ���
	
	printf("\n������ �ڵ� ��\n");
	printf("10����: %d, 8����: %#o, 16����: %#x\n", input, input, input);		// �Էµ� ���ڸ� printf�� 10����, 8����, 16������ ���
	return 0;
}