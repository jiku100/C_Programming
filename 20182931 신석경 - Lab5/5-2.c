/*
* �Է��� �µ� �������� ���� F�� f�̸� �Է� ���� ���� ȭ���µ��� �����Ͽ� �����µ��� �ٲٰ�, 
* �Է� ���� ���ڰ� C�� c�̸� �Է� ���� ���� �����µ��� �����Ͽ� ȭ���µ��� �ٲپ� ����� ����ϴ� ���α׷�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define to_F(C) ((9/5.) * C + 32)	// ȭ�� ��ȭ ��ũ��
#define to_C(F) ((5/9.) * (F - 32))	// ���� ��ȭ ��ũ��


int main(void) {
	printf("�Է��� �µ��� ��ȯ�մϴ�.\n\n");
	
	double number;	// ���� ���� ����
	char input[128];	// �Էµ� ���ڿ��� �����ϱ� ���� �迭
	char* pos = NULL;
	while (1) {
		printf("�µ��� �������� F,f,C,c�� �ٿ��� �Է��Ͻÿ�\n");
		printf("�µ��Է�<��: 30.4c, 45.3f> >> ");
		scanf("%s", input);
		number = strtod(input, &pos);		// �Էµ� ���ڿ����� double�� ���ڸ� ��ȯ�ϰ� �� ������ ��ġ�� pos�� ����
		if (strcmp(pos, "F") == 0 || strcmp(pos, "f") == 0) {
			printf(" ȭ�� �µ� %.2f�� ���� �µ��� %.2f�Դϴ�.\n\n", number, to_C(number));
		}
		else if (strcmp(pos, "C") == 0 || strcmp(pos, "c") == 0) {
			printf(" ���� �µ� %.2f�� ȭ�� �µ��� %.2f�Դϴ�.\n\n", number, to_F(number));
		}
		else {
			printf("\n�߸��� ���ڸ� �Է��߽��ϴ�.\n\n");
			while (getchar() != '\n');
		}
	}

}