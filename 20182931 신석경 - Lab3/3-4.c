/*
* ������ �Է� �޾� 32��Ʈ�� ��Ʈ ������ ��� ����ϴ� ���α׷�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	printf("������ �Է� �޾� 32��Ʈ�� ���\n\n");

	int num;	// �Է� ���� ����
	
	while(1){
		printf("������ �Է��Ͻÿ� >> ");
		scanf("%d", &num);
		if (num == 0)
			break;
		else {
			for (int i = 31; i >= 0; i--)	// 32���� ��Ʈ
				printf("%d", num >> i & 1);	// �ϳ��� ��Ʈ�� 1�� &������ ���� �˾Ƴ�
			printf("\n\n");
		}
	}
	printf("���α׷��� �����մϴ�.\n\n");
	return 0;
}