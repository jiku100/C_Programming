#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum GAME {		// enum ����
	ROCK = 0,
	SCISSORS,
	PAPER
};

void doGame(enum GAME computer, int op);	// ����� Ȯ���ϱ� ���� �Լ�

int main(void) {
	enum GAME computer;
	int op;
	printf("��ǻ�Ϳ� ���� ���� �� ������ �����մϴ�.\n");
	srand((unsigned int)time(NULL));

	while (1) {
		computer = rand() % 3;	// �������� ����
		printf("����<0> ����<1> ��<2> ����<3> �߿��� �ϳ� �Է� >> ");
		scanf("%d", &op);
		if (op >= 0 && op < 3)	// 0, 1, 2�̸� ��� ���
			doGame(computer, op);
		else if (op == 3) break;	// 3�̸� ����
		else   // �ٸ� ���̸� �ٽ� �Է�
			printf("�߸� �Է��߽��ϴ�. �ٽ� �Է��ϼ���.\n\n");
	};
	printf("���α׷��� �����մϴ�.\n\n");
	return 0;
}

void doGame(enum GAME computer, int op) {
	switch (computer)
	{
	case ROCK:	// ��ǻ�Ͱ� �ָ��̸�
		switch (op)		// �Է°��� ���� ��� ���
		{
		case ROCK:
			printf("�����ϴ�. �ٽ��ϼ���.\n\n");
			break;
		case SCISSORS:
			printf("��ǻ���� �¸��Դϴ�.\n\n");
			break;
		case PAPER:
			printf("����� �¸��Դϴ�.\n\n");
			break;
		}
		break;
	case SCISSORS:
		switch (op)
		{
		case ROCK:
			printf("����� �¸��Դϴ�.\n\n");
			break;
		case SCISSORS:
			printf("�����ϴ�. �ٽ��ϼ���.\n\n");
			break;
		case PAPER:
			printf("��ǻ���� �¸��Դϴ�.\n\n");
			break;
		}
		break;
	case PAPER:
		switch (op)
		{
		case ROCK:
			printf("��ǻ���� �¸��Դϴ�.\n\n");
			break;
		case SCISSORS:
			printf("����� �¸��Դϴ�.\n\n");
			break;
		case PAPER:
			printf("�����ϴ�. �ٽ��ϼ���.\n\n");
			break;
		}
		break;
	}
}