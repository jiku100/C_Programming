#include <stdio.h>

struct person {
	char name[20];
	char phonenumber[14];
	char address[64];
};


int main(void) {
	struct person p1 = { "ȫ�浿", "011-1111-1111", "����� ���α� ��ô��" };
	struct person p2 = { "�̼���", "017-3245-3278", "����� ������ ���" };
	struct person p3 = { "�ڹ���", "011-2222-2456", "��⵵ �Ⱦ�� ��굿" };

	printf("--------------------------------------------------\n");
	printf("    �� ��       ��ȭ��ȣ                 �� ��\n");
	printf("--------------------------------------------------\n");
	printf("  %s    %s\t%s\n", p1.name, p1.phonenumber, p1.address);
	printf("  %s    %s\t%s\n", p2.name, p2.phonenumber, p2.address);
	printf("  %s    %s\t%s\n", p3.name, p3.phonenumber, p3.address);
	printf("--------------------------------------------------\n");
	return 0;
}