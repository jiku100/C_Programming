/*
* ������ �迭�� �������� �˻��Ͽ� �� ����� �˾ƺ��� ���α׷�
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(void) {
	printf("������ �迭�� �������� �˻��Ͽ� ��� ���\n\n");

	int a[] = { 4, 7, 9, 3, 6 };
	int b1[] = { 4, 7, 9, 3, 6 };   // ���� ���
	int b2[] = { 4, 7, 9, 3, 7 };   // ������ ���Ұ� �ٸ� ���
	int b3[] = { 4, 7, 9, 3, 6, 8 }; // ������ ������ �ٸ� ���

	int size = sizeof(a) / sizeof(a[0]);	// a �迭�� ���� ����

	int isequal = TRUE;	// �迭�� �������� �����ϴ� ���� 

	printf("a[]  : ");
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
		printf("%d  ", a[i]);	// a���� ���

	printf("\nb1[] : ");
	for (int i = 0; i < sizeof(b1) / sizeof(b1[0]); i++)
		printf("%d  ", b1[i]);	// b1���� ���

	if(size != (sizeof(b1)/sizeof(b1[0])))
		isequal = FALSE;	// �� �迭�� ���̰� �ٸ��� FALSE

	if (isequal) {	// �� �迭�� ���̰� ������
		for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
			// a�� �������� b1�� �������� Ȯ���ϴ� ����
			if (b1[i] != a[i])	// �� ���Ұ� �ٸ���
				isequal = FALSE;	// isequal == FALSE
		}
	}
	if (isequal == FALSE)
		printf("\n�� �迭�� �ٸ���.\n\n");
	else
		printf("\n�� �迭�� ����.\n\n");

	isequal = TRUE;	// �ٽ� �ʱ�ȭ




	printf("a[]  : ");
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
		printf("%d  ", a[i]);	// a���� ���

	printf("\nb2[] : ");
	for (int i = 0; i < sizeof(b2) / sizeof(b2[0]); i++)
		printf("%d  ", b2[i]);	// b2���� ���

	if (size != (sizeof(b2) / sizeof(b2[0])))
		isequal = FALSE;	// �� �迭�� ���̰� �ٸ��� FALSE

	if (isequal) {	// �� �迭�� ���̰� ������
		for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
			// a�� �������� b2�� �������� Ȯ���ϴ� ����
			if (b2[i] != a[i])	// �� ���Ұ� �ٸ���
				isequal = FALSE;	// isequal == FALSE
		}
	}
	if (isequal == FALSE)
		printf("\n�� �迭�� �ٸ���.\n\n");
	else
		printf("\n�� �迭�� ����.\n\n");

	isequal = TRUE;	// �ٽ� �ʱ�ȭ



	printf("a[]  : ");
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
		printf("%d  ", a[i]);	// a���� ���

	printf("\nb3[] : ");
	for (int i = 0; i < sizeof(b3) / sizeof(b3[0]); i++)
		printf("%d  ", b3[i]);	// b3���� ���
	
	if (size != (sizeof(b3) / sizeof(b3[0])))
		isequal = FALSE;	// �� �迭�� ���̰� �ٸ��� FALSE

	if (isequal) {	// �� �迭�� ���̰� ������
		for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
			// a�� �������� b3�� �������� Ȯ���ϴ� ����
			if (b3[i] != a[i])	// �� ���Ұ� �ٸ���
				isequal = FALSE;	// isequal == FALSE
		}
	}
	if (isequal == FALSE)
		printf("\n�� �迭�� �ٸ���.\n\n");
	else
		printf("\n�� �迭�� ����.\n\n");

	return 0;
}