#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
* RGB�� Red, Green, Blue�� �Է¹޾� ������ ����Ʈ���� ���ʴ�� �����ϰ� ����ϴ� ���α׷�
*/

int main(void) {
	printf(" RGB�� Red, Green, Blue�� �Է¹޾� ������ ����Ʈ���� ���ʴ�� �����ϰ� ���\n\n");

	int red, green, blue; // ������ ������ ������ ����
	printf("�÷����� ���ʷ� �Է��Ͻÿ�\n");
	printf("red : "); scanf("%d", &red);
	printf("green : "); scanf("%d", &green);
	printf("blue : "); scanf("%d", &blue);

	int rgb = 0;	// rgb color�� �����ϴ� ����;
	rgb = (rgb + blue) << 8;	// ������ ����Ʈ�� ���� �����ϰ� ��Ʈ�� �ø�
	rgb = (rgb + green) << 8;
	rgb = (rgb + red);			// red�� ��� ���� ���常 �ϰ� ��Ʈ�� �ø��� ����

	printf("RGB Color: %x\n", rgb);
	return 0;
}