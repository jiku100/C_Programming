/*
* ���ڸ� ����(10~ 99) ������ ����(random number)�� 20�� �����Ͽ� �迭�� �����ϰ�
* ����ڰ� 5���� ���ڸ� �Է��Ͽ� �� ���� ���ߴ��� �˻��ϴ� ���α׷�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void initRand(int* number);
void check(int* random, int* input);

int main(void) {
	int random[20] = { 0, };
	int input[5] = { 0, };
	srand((long)time(NULL));	// seed �ʱ�ȭ
	while (1) {
		initRand(random);
		printf("���ڸ���<10 ~ 99> 20���� random number �� �����մϴ�.***************************\n");
		printf("���� �ٸ� ���� 5��<10 ~ 99>�� �Է��Ͻÿ� >> ");
		scanf("%d %d %d %d %d", input, input + 1, input + 2, input + 3, input + 4);	// �迭�� �Էµ� ���� ����
		check(random, input);	// ���� ���� �� Ȯ��
	}
	return 0;
}

void initRand(int* number) {	// ���� ���� �Լ�
	for (int i = 0; i < 20; i++) {
		number[i] = (rand() % 90) + 10;	// 10 ~ 99 ������ ���� 20�� �����ؼ� number�� ����
	}
}

void check(int* random, int* input) {
	int result = 0;

	for (int i = 0; i < 20; i++) {	// random�� 20�� �߿� �ϳ���
		for (int j = 0; j < 5; j++) {	// input�� 5���� �˻��ؼ�
			if (random[i] == input[j])
				result++;	// ������ ���� ����
		}
	}
	printf("���� ������ %d�� �Դϴ�.\n\n", result);
}