#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printHigher(int count, int input, int down_boundary, int up_boundary); // target�� �� ���� ��� ���
void printLower(int count, int input, int down_boundary, int up_boundary);  // target�� �� ���� ��� ���

int main(void) {
	srand((unsigned int)time(NULL));
	int target =  rand() % 100 + 1;	// 1 ~ 100 �ʱ�ȭ
	
	int input;
	int count = 0;

	int up_boundary = 100;	// ó�� up_boundary = 100 
	int down_boundary = 1;	// ó�� down_boundary = 1

	printf("1���� 100������ �ϳ��� ������ �����Ǿ����ϴ�.\n");
	printf("�� ������ ���� ���ÿ�? >> "); 
	scanf("%d", &input);	// ù �Է�
	putchar('\n');
	count++;	// ī��Ʈ 1

	for (count; count < 6; count++) { // ī��Ʈ�� 1 ���� 5���� �˻�
		if (target < input) {	// target ���� input�� ũ��
			up_boundary = input - 1;	// boundary �缳��
			printLower(count, input, down_boundary, up_boundary);	// ���ٴ� �޼��� ���
		}
		else if (target > input) {	// ������
			down_boundary = input + 1;	// boundary �缳��
			printHigher(count, input, down_boundary, up_boundary);	// �۴ٴ� �޼��� ���
		}
		else {	// ������
			printf("�����մϴ�. �õ����� %d������ ���� %d �� �������ϴ�.\n\n", count, target);
			break;	// ��� �� ����
		}
		if (count < 5) {	// ���� ī��Ʈ�� 5���� ������
			scanf("%d", &input);	// �ٽ� �Է��� �޴´�.
			putchar('\n');
		}
	}
	if (count == 6) {	// for���� count == 6�� �� ���� ���� ������ ���� ��
		printf("\n�ִ� �õ� Ƚ���� 5ȸ ���� ������ ���Ͽ����ϴ�. ���α׷��� �����մϴ�.\n\n");
	}

	return 0;
}

void printHigher(int count, int input, int down_boundary, int up_boundary) {
	printf("���߾�� �� ������ �Է��� ���� %d ���� Ů�ϴ�. <�õ�Ƚ��: %d>\n", input, count);
	if(count<5)	// ī��Ʈ�� 5 �Ʒ� �� ���� �ٽ� �Է� �ޱ� ���� �޼��� ���
		printf("%d���� %d������ ������ �ٽ� �Է��ϼ���. > ", down_boundary, up_boundary);
}
void printLower(int count, int input, int down_boundary, int up_boundary) {
	printf("���߾�� �� ������ �Է��� ���� %d ���� �۽��ϴ�. <�õ�Ƚ��: %d>\n", input, count);
	if (count < 5)
		printf("%d���� %d������ ������ �ٽ� �Է��ϼ���. > ", down_boundary, up_boundary);
}

