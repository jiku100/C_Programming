/*
* �־��� ���ڿ��� �빮��, �ҹ���, ����, Ư�����ڰ� ���� ����� ���ϴ� ���α׷�
*/

#include <stdio.h>

int main(void) {
	printf("���̺귯���� ������� �ʰ� �־��� ���ڿ��� ������ �ľ�\n\n");

	char* str = "abC*12dE3%4";	// ���ڿ� ����
	int upper = 0, lower = 0, number = 0, special = 0; 
	// ���� �빮��, �ҹ���, ����, Ư�� ���ڿ� ���� ���� �ʱ�ȭ
	char temp;	// �ϳ��� ���ڸ� �����ϱ� ���� �ӽ� ����

	printf("���ڿ� %s\n\n", str);
	int i = 0;
	while (*(str + i) != NULL) {	
		// ���ڰ� NULL�� �ƴϸ� (���ڿ� �������� NULL�� �����Ƿ� NULL������ �˻�)

		temp = *(str + i);	// �ϳ��� ���� ����

		if (temp >= 'A' && temp <= 'Z') {	// �빮���̸�
			upper++;	// upper ���� 1 ����
		}
		else if (temp >= 'a' && temp <= 'z') {	// �ҹ����̸�
			lower++;	// lowere ���� 1 ����
		}
		else if (temp >= '0' && temp <= '9') {	// �����̸�
			number++;	// number ���� 1 ����
		}
		else {		// ������ �� Ư�� �����̸�
			special++;	// special ���� 1 ����
		}

		i++;	// �� ���� ���ڷ� �̵�
	}

	printf("�빮�ڴ� %d��\n", upper);	// �빮�� ���� ���
	printf("�ҹ��ڴ� %d��\n", lower);	// �ҹ��� ���� ���
	printf("���ڴ� %d��\n", number);	// ���� ���� ���
	printf("Ư�����ڴ� %d��\n", special);	// Ư������ ���� ���

	printf(">>> ��ü ���ڼ��� %d�� �Դϴ�.\n\n", upper + lower + number + special);	// ��ü ���� ���
	return 0;

}