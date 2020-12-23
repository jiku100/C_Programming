/*******************************************************
* ���ϸ�: calFat.c
* ���α׷� ����: ����, Ű, �����Ը� �̿��Ͽ� �񸸵��� ����ϴ� ���α׷�
*	ǥ�� ü��: standardWeight �Լ� ����
*	�� ����: CALFAT ��ũ�� ����
*   WEIGHT_PARAM_MAN: ǥ�� ü���� ���ϱ� ���� ���ڿ��� ����Ǵ� ��� 22 ����
*	WEIGHT_PARAM_WOMAN: ǥ�� ü���� ���ϱ� ���� ���ڿ��� ����Ǵ� ��� 21 ����
* 
* 
*	�Է� 1: ������ �Է¹޴� �ϳ��� ����
*   �Է� 2: ����(Ű)�� �����Ը� �Է� �޴� �� �Ǽ�
*
*   ���: ǥ�� ü��, �� ������ ����ϰ� �׿� ���� �񸸵� ���� ����� ���
*
* ��¥: 2020�� 9�� 11��
* ����: 1.0
* �ۼ���: 20182931 �ż���
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define WEIGHT_PARAM_MAN 22	// ���� ǥ�� ü���� ���ϱ� ���� ���
#define WEIGHT_PARAM_WOMAN 21	// ���� ǥ�� ü���� ���ϱ� ���� ���

#define CALFAT(weight, standard) ((weight / standard) * 100)	//�񸸵��� ����ϴ� ��ũ��

float standardWeight(int op, float height);	// ǥ�� �����Ը� ����ϴ� �Լ�

int main(void) {
	int op;	// ������ �����ϴ� ����
	float height, weight;	// Ű�� �����Ը� �����ϴ� ����

	int n;	// �Է� ���� ���� ���� ����

	float standard, fat; // ǥ�� ü�߰� �� ������ �����ϴ� ����

	while (1) {
		printf("������ �Է��ϼ���. 0<����> 1<����>, 2<����>: ");		// ���� ����
		scanf("%d", &op);

		if (op == 1 || op == 2) {	// ���� Ȥ�� �����̸�
			while (1) {
				printf("����<cm>�� ������<kg>�� �Է��ϼ���: ");	// ����� ������ �Է� �ޱ�
				n = scanf("%f %f", &height, &weight);	// ��Ȯ�ϰ� ������ n == 2

				if (n == 2 && height > 0 && height <= 200 && weight > 0 && weight < 100) {	
					// �� ���� �Է��� ������ 0 < height < 200, 0< weight < 100 ������ ������ ���

					standard = standardWeight(op, height);  // ������ ���� ǥ�� ü�� ���
					fat = CALFAT(weight, standard);	// �� ���� ���

					printf(" ���� ����: %.2f, ü��: %.2f\n", height, weight);
					printf(" ǥ�� ü��: %.2f, ������: %.2f\n", standard, fat);

					if (fat < 90)		// 10���� �̸��� ���
						printf("�񸸵� ���� ��� : \"ü�� �̴�\"�Դϴ�.\n\n");
					else if (fat >= 90. && fat <= 100.)	// +- 10������ ���
						printf("�񸸵� ���� ��� : \"����\"�Դϴ�.\n\n");
					else if (fat > 110. && fat <= 120)	// 10���� �ʰ� �� 20���� �̸��� ���
						printf("�񸸵� ���� ��� : \"ü�� ����\"�Դϴ�.\n\n");
					else	// 20���� �ʰ��� ���
						printf("�񸸵� ���� ��� : \"��\"�Դϴ�.\n\n");
					break;
				}
				else {		// �ٸ� �Է��� ���� ���
					printf("���� �Ǵ� �����Ը� �߸� �Է� �Ͽ����ϴ�.\n");	// ���� ���
					while (getchar() != '\n');		// �Է� ���� ����
				}
			}
		}
		else if (op == 0) {	// ���Ḧ ���� ��
			printf("**** ���α׷��� �����մϴ�. **** \n\n");
			break;
		}
		else {	// 1, 2�� �ش��ϴ� �ɼ��� ������ ���� ���
			printf("������ �߸� �Է� �Ͽ����ϴ�.\n\n");	// ���� ���
			while (getchar() != '\n');		// �Է� ���� ����
		}
	}
	return 0;
}

float standardWeight(int op, float height) {	// ǥ�� �����Ը� ����ϴ� �Լ�
	// ����, ������ �Է� �޾� ǥ�� ü���� ���
	// ������ ������ 1(����) �ƴϸ� 2(����)�� �Էµ�. ���ܴ� �Լ��� ����ϱ� ���� �˻�

	float height_meter = height / 100;	// cm ������ m�� ��ȯ�Ͽ� ���� ����
	if (op == 1) {	// ������ �����̸�
		return height_meter * height_meter * WEIGHT_PARAM_MAN;	// ������ ��� ǥ�� ü�� = ����(m) * ����(m) * 22 ���
	}
	else {		// ������ ������ ���
		return height_meter * height_meter * WEIGHT_PARAM_WOMAN; // ������ ��� ǥ�� ü�� = ����(m) * ����(m) * 21 ���
	}
}