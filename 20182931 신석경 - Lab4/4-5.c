/*
* 0���� 9������ ���� �߿��� 10���� ���� �Է� �޾� 
* ���� ���� �Է� ���� �� ���� �����̰�, �� ������ ����ϴ� ���α׷��� 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(void) {
	printf("0 ~ 9������ ���� 10�� �Է� �޾� �ֺ󰪰� Ƚ���� ���\n\n");

	int count[10] = { 0, };	// ��� Ƚ���� 0���� �ʱ�ȭ
	
	int input, n;	// scanf�� ���� ���� ������ ����, �ùٸ� �Է����� Ȯ���ϴ� ����

	int i = 0;	// �Է��� Ƚ���� �����ϴ� ����

	int isRight = TRUE;	// �ùٸ� �Է����� ���¸� �����ϴ� ����

	printf("0���� 9������ ������ �Է��Ͻÿ�.\n");

	while (i < 10) {	// �� 10�� �Է� ����
		if (isRight == FALSE) {	// ���� �Է��� �ùٸ��� ���� ���
			while (getchar() != '\n');
			printf("�ٽ��Է�<0 ~ 9> : ");
		}
		n = scanf("%d", &input);
		if (n == 1 && input >= 0 && input <= 9) {	// �Է��� 0 ~ 9�� ���
			isRight = TRUE;	// �ùٸ� �Է� ���� ����
			count[input]++;	// �ش� index 1 ����
			i++; // Ƚ�� 1 ����
		}
		else {		// �ùٸ� �Է��� �ƴ� ���
			isRight = FALSE;	// �߸��� �Է� ���� ����
		}
	}

	int max_index = 0;	// �ֺ� index �����ϴ� ����

	for (int j = 0; j < sizeof(count) / sizeof(count[0]); j++) {
		if (count[j] > count[max_index])
			// j index�� count ���� max_index�� count ������ Ŭ ���
			max_index = j;	// max_index �� j�� �ٲ�
	}

	// �ֺ󰪰� Ƚ�� ���
	printf("\n0 ~ 9 �� ���� ���� ���� ���� %d�̰�, %d�� ���Խ��ϴ�.\n\n", max_index, count[max_index]);
	
	return 0;
}