#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ConvertToSquareMeter(x) ((x)*3.305785) // �� ������ �������� ������ �ٲٱ� ���� ��ũ��


/*
* �� ���� ����Ʈ ������ ���� ���� ���ڰ� ���Ե� ǥ���Է����� �޾� �������ͷ� ����ϴ� ���α׷�
*/

int main(void) {
	printf("�� ���� ����Ʈ ������ �Է� �޾� �������ͷ� ���\n");
	printf("���� ���ڴ� /�� �Ѵ�. ex. 25/31/45\n\n");		// /���ڷ� �Է��� ����

	printf("�� ���� ����Ʈ ������ �Է��ϼ���.: ");
	int area1, area2, area3;
	scanf("%d/%d/%d", &area1, &area2, &area3);		// �� ���� ������ �Է� ����.

	printf("%d�� = %f (m^2)\n", area1, ConvertToSquareMeter(area1));		// �Էµ� ���� ��ũ�θ� ����� �������ͷ� ��ȯ
	printf("%d�� = %f (m^2)\n", area2, ConvertToSquareMeter(area2));
	printf("%d�� = %f (m^2)\n", area3, ConvertToSquareMeter(area3));

	return 0;
}