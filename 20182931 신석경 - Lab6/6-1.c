/*
* ������ �迭�� �������� �˻��Ͽ� �� ����� �˾ƺ��� ���α׷�
*/

#include <stdio.h>

void displayarray(int ary[], int size);	//display array elemnet
int isequalarray(int a[], int b[], int asize, int bsize);  // compare array a with b, return 1 or 0

int main(void) {
	int a[] = { 4, 7, 9, 3, 6 };
	int b1[] = { 4, 7, 9, 3, 6 };   // ���� ���
	int b2[] = { 4, 7, 9, 3, 7 };   // ������ ���Ұ� �ٸ� ���
	int b3[] = { 4, 7, 9, 3, 6, 8 }; // ������ ������ �ٸ� ���

	printf("a[]   : ");
	displayarray(a, sizeof(a) / sizeof(int));	// ��� ���
	printf("b1[]  : ");
	displayarray(b1, sizeof(b1) / sizeof(int));	// ��� ���
	isequalarray(a, b1, sizeof(a) / sizeof(int), sizeof(b1) / sizeof(int));	// ��

	printf("a[]   : ");
	displayarray(a, sizeof(a) / sizeof(int));	// ��� ���
	printf("b2[]  : ");
	displayarray(b2, sizeof(b2) / sizeof(int));	// ��� ���
	isequalarray(a, b2, sizeof(a) / sizeof(int), sizeof(b2) / sizeof(int));	// ��

	printf("a[]   : ");
	displayarray(a, sizeof(a) / sizeof(int));	// ��� ���
	printf("b3[]  : ");
	displayarray(b3, sizeof(b3) / sizeof(int));	// ��� ���
	isequalarray(a, b3, sizeof(a) / sizeof(int), sizeof(b3) / sizeof(int));	// ��
	return 0;
}


void displayarray(int ary[], int size) {	// ��� ���
	for (int i = 0; i < size; i++)
		printf("%3d", ary[i]);
	printf("\n");
}

int isequalarray(int a[], int b[], int asize, int bsize) {
	if (asize != bsize) {	// ���̰� �ٸ��� �ٸ�
		printf("�� �迭�� �ٸ���.\n\n");
		return -1;
	}
	else {	// �迭�� ���̰� ���� ��
		for (int i = 0; i < asize; i++) {
			if (a[i] != b[i]) {	 // ���� index�� ���Ұ� �ٸ��� �ٸ�
				printf("�� �迭�� �ٸ���.\n\n");
				return -1;
			}
		}
	}

	printf("�� �迭�� ����.\n\n");
	return 0;
}