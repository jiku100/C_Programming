/*******************************************************
* ���ϸ�: magicsquare.c
* ���α׷� ����: �������� �׸��� ���α׷�
*	������ ����: magicSquare() �Լ� ���
*	������ �׸���: printSquare() ����
*
*	�Է� 1: �������� �� ���� ���̸� ��Ÿ���� Ȧ�� n
*
*	���: ������
*
* ��¥: 2020�� 11�� 04��
* ����: 1.0
* �ۼ���: 20182931 �ż���
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void magicSquare(int** square, const int n); // ������ ���� �Լ�
void printSquare(int** square, const int n);	// ������ �׸��� �Լ�


int main(void) {
	int n;	// ������ �� ���� ���̸� �����ϴ� ����
	printf("�������� ���� Ȧ�� ���� n�� �Է��ϼ���.(n>2) n ==> ");
	while (scanf("%d", &n) != 1 || n % 2 == 0 || n < 2) {	// �ùٸ� �Է��� ���� ������
		while (getchar() != '\n');
		if (n % 2 == 0)
			printf("%d�� ¦���Դϴ�. �ٽ� �Է��Ͻÿ�.\n", n);
		else if (n < 2)
			printf("2 ���� ū Ȧ���� �Է��Ͻÿ�.\n");
		else
			printf("������ �Է��Ͻÿ�.\n");
		printf("�������� ���� Ȧ�� ���� n�� �Է��ϼ���.(n>2) n ==> ");
	}
	
	int** square = calloc(n, sizeof(int*));   
	// ���� �����Ϳ� (int ������ ũ�� * n)��ŭ ���� �޸� �Ҵ�. �� �ǹ�

	for (int i = 0; i < n; i++)            // �� ũ�⸸ŭ �ݺ�
	{
		square[i] = calloc(n, sizeof(int));    // (int�� ũ�� * n)��ŭ ���� �޸� �Ҵ�. �� �ǹ�
	}

	magicSquare(square, n);	// ������ ����
	printSquare(square, n);	// ������ �׸���
	return 0;
}

void magicSquare(int** square, const int n) { // ������ ���� �Լ�
	int x = n / 2;	// ó�� �׸� x ��ġ�� ���� ���
	int y = 0;		// ó�� �׸� y ��ġ�� ù ��° ��
	int count = 1;	// ó�� �׸� ���ڴ� 1
	while(1){	
		square[y--][x++] = count++;	
		if (count > n * n) { // �� n * n���� ���ڸ� ����
			break;	// ��� ��Ŀ� ���� �ָ� break
		}
		// ��ġ�� ���ڸ� �׸���, ������ ������� ���ϴ� �밢������ ��ǥ �̵� count 1 ����
		if (x > n - 1 && y < 0) {	// ������ ǥ�� ��� ���
			x -= 1;
			y += 2;
			// �ٷ� �� ĭ�� �Ʒ��� �̵�
		}
		if (x > n - 1) {	// x ��ǥ�� ���� index�� �Ѿ��
			x = 0;	// 0�� index�� �̵�
		}
		if (y < 0) {		// y ��ǥ�� ���� index�� -�� �Ѿ��
			y = n - 1;	// n-1�� index�� �̵�
		}
		else if (y > n - 1) {	// y ��ǥ�� ���� index�� +�� �Ѿ��
			y = 0;	// 0���� �̵�
		}

		while (square[y][x] != 0) {	// �̵��� ���� ������� ������
			x -= 1;
			y += 1;
			// ���� ĭ���� �̵� ��
			y += 1;	// �Ʒ� ĭ���� �̵�
			if (y < 0) {		// y ��ǥ�� ���� index�� -�� �Ѿ��
				y = n - 1;	// n-1�� index�� �̵�
			}
			else if (y > n - 1) {	// y ��ǥ�� ���� index�� +�� �Ѿ��
				y = 0;	// 0���� �̵�
			}
		}
	}
}

void printSquare(int** square, const int n) {	// ������ �׸��� �Լ�
	printf("\n n�� %d�� �������� ����� ������ �����ϴ�.\n\n", n);
	int sum = 0;
	for (int y = 0; y < n; y++) {		// 2���� �迭�� ����ϴ� for��
		for (int x = 0; x < n; x++) {
			printf("%5d", square[y][x]);
			sum += square[y][x];		// y ��° ���� ���� ���� sum���� ����
		}
		printf("  |%5d", sum);		// y ��° �� ���� �� ���
		sum = 0;
		printf("\n");
	}
	for (int i = 0; i < n; i++) {
		printf("  ---");
	}
	printf("\n");
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			sum += square[y][x];		// x ��° ���� ���� ���� sum���� ����
		}
		printf("%5d", sum);	// x ��° �� ���� �� ���
		sum = 0;
	}
	printf("\n");
}