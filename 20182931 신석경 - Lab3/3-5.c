/*
* �ΰ��� 16������ �Է����� �޾� ��Ʈ ������ �����ϴ� ���� ���α׷�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	printf("2���� 16������ �Է� �޾� ��Ʈ ���� ��� ���\n\n");

	int x, y;	// �� 16���� ���� ����
	char op;	// ������ ���� ����
	int n;	// �Է� ���� ����
	
	while (1) {
		printf("16����<4�ڸ�> �� ���� �Է��Ͻÿ�(����� -1 -1) >> ");
		n = scanf("%x %x", &x, &y);	// 16���� �� ���� ����
		if (x == -1 && y == -1)		// �Է��� -1 -1�� ��� ���� while�� Ż��
			break;
		else if (n != 2 || x < 0 || x>0xffff || y < 0 || y > 0xffff) {	// �Է��� �߸��� ���
			while (1) {		// ���� while��: �Է��� ����� ���� ������ �ݺ�
				while (getchar() != '\n');		// �Է� ���� ����
				printf(" ?? �ٽ� �Է��Ͻÿ� : ");
				n = scanf("%x %x", &x, &y);	// 16���� �� ���� ����
				if (n == 2 && x >= 0 && x < 65536 && y >= 0 && y < 65536) {	// input�� 0x0000 0xffff ������ ��
					break;		// ���� while�� Ż��
				}
			}
		}
		if (n == 2 && x >= 0 && x < 65536 && y >= 0 && y < 65536) {	// input�� 0x0000 0xffff ������ ��
			while (1) {		// ���� while��: �����ڰ� ����� ���� ������ �ݺ�
				printf("�����ڸ� �Է��Ͻÿ�[&, |, ^] : ");
				scanf(" %c", &op);
				if (op == '&' || op == '|' || op == '^') {		// �ùٸ� ������ �� ���
					switch (op)
					{
					case '&': printf(" >> ���� ���: %#6x\n\n", x & y); break;
					case '|': printf(" >> ���� ���: %#6x\n\n", x | y); break;
					case '^': printf(" >> ���� ���: %#6x\n\n", x ^ y); break;
					default:
						break;
					}
					break;	// ���� while�� Ż��
				}
				else {
					printf(" ?? �����ڸ� �߸� �����ϼ̽��ϴ�.\n");
					while (getchar() != '\n');		// �Է� ���� ����
				}
			}
		}
		else if (x == -1 && y == -1)	// ù��° ���� while�� �Է��� -1 -1 �� ���
			break;		// ���� while�� Ż��
	}
	printf("���α׷��� �����մϴ�.\n\n");

	return 0;
}