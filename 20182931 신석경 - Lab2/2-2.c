#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*
* ������ õ�� ������ �� ���� �Է� �޾� 
* �츮�� ����ϴ� ������ ��, õ, ��, ��, �� ������ ����ϴ� ���α׷�
*/

int main(void) {
	printf("������ õ�� ������ �� ���� �Է� �޾� �츮�� ����ϴ� ������ ��, õ, ��, ��, �� ������ ���\n\n");

	int target; // �Է� ���� ����
	printf("õ�� ������ ������ �Է��ϼ���: ");
	scanf("%d", &target);

	int ten = 10;
	char* unit[5] = { " ", "�� ", "�� ", "õ ", "�� " };

	int divisor; // ������ ��

	printf("�Է�: %d\n", target);
	for (int i = 4; i >= 0; i--) {
		divisor = pow(10, i);
		if (target / divisor != 0) {	// ������ �ش��ϴ� ���ڰ� ������
			printf("%d %s", target / divisor, unit[i]);	// ���
			target -= (target / divisor) * divisor;		// ��� ���� ��� �κ� ����
		}
	}

	printf("�Դϴ�.\n");
	return 0;	
}