#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
* 1��б�: 1, 2, 3��, 2��б�: 4, 5, 6��, 3��б�: 7, 8, 9��, 4��б�: 10, 11, 12��
* ���� �����Ͽ� �Է� ���� ���� �ش�Ǵ� �б⸦ ����ϴ� ���α׷�
*/

int main(void) {
	printf("�Է� ���� ���� �ش�Ǵ� �б⸦ ���. ��, if �� ���\n\n");

	int month;	// �Է��� ������ ����;
	
	printf("��(month)�� �Է��ϼ���. : ");
	scanf("%d", &month);

	int quarter; // �� �б� ���� ������ ����

	if (month < 4)
		quarter = 1;
	else if (month >= 4 && month < 7)
		quarter = 2;
	else if (month >= 7 && month < 10)
		quarter = 3;
	else
		quarter = 4;
	
	printf("%d ���� %d ��б� �Դϴ�.\n", month, quarter);
	return 0;
		
}