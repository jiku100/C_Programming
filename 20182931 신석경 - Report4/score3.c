/*******************************************************
* ���ϸ�: score3.c
* ���α׷� ����: in.txt���� ����ü�� �о� �� �л��� ������ ���� ���Ͽ� ����ϰ� out.txt���Ͽ� ����
*	���� �հ�: calSum() ���
*	��� ���� ���� �� ���: printOut() ����
*
*	���: �� �л����� ����
*
* ��¥: 2020�� 11�� 24��
* ����: 1.0
* �ۼ���: 20182931 �ż���
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct student {
	int order;
	char name[16];
	float score1;
	float score2;
	float sum;
};
typedef struct student student;

void calSum(student* st, int number);	// ���� �� ��� �Լ�
void printOut(FILE* out, student* st, int number);	// �л� ����ü�� ������ out file�� ����ϴ� �Լ�

int main(void) {
	FILE* in, * out;	// in, out stream

	if ((in = fopen("in.txt", "r")) == NULL) {	// in.txt �� �б� �������� ����
		printf("in.txt ������ ���� �� �����ϴ�.\n");
		exit(1);
	}

	if ((out = fopen("out.txt", "w")) == NULL) {	// out.txt �� ���� �������� ����
		printf("out.txt ������ �� �� �����ϴ�.\n");
		exit(1);
	}

	char line[80];	// �� ���� �о�� ����
	int cnt = 0;	// ������ ������ ����
	student st[10];	// 10���� �л��� ������ �� �ִ� ����ü �迭 ����

	while (!feof(in)) {
		fgets(line, 80, in);	// in���� �� ���� �о��
		// �Ʒ��� ���Ĵ�� in.txt���� ����ü ������ �и���
		sscanf(line, "%d    %s    %f    %f", &st[cnt].order, st[cnt].name, &st[cnt].score1, &st[cnt].score2);
		cnt++;
	}

	printf("--------------------------------------------\n");
	printf("%5s%8s%10s%8s%10s\n", "��ȣ", "�̸�", "����1", "����2", "�հ�");
	printf("============================================\n");
	calSum(st, cnt);	// �� �л����� ���� ���� ����Ͽ� st.sum�� ����
	printOut(out, st, cnt);	// �� �л����� ������ ȭ�鿡 ��� �� out.txt�� ����
	printf("--------------------------------------------\n");

	fclose(in);
	fclose(out);
	return 0;


}
void calSum(student* st, int number) {
	for (int i = 0; i < number; i++) {	// number ���� �� �л����� ���� �հ踦 ����Ͽ� ����
		st[i].sum = (st[i].score1 + st[i].score2);
	}
}

void printOut(FILE* out, student* st, int number) {
	for (int i = 0; i < number; i++) {
		// �� st�� ������ ���Ŀ� ���缭 out�� ����
		fprintf(out, "%d    %s    %.1f    %.1f    %.1f\n", st[i].order, st[i].name, st[i].score1, st[i].score2, st[i].sum);
		// ȭ�鿡 ���
		printf("%3d%12s%8.1f%8.1f%10.1f\n", st[i].order, st[i].name, st[i].score1, st[i].score2, st[i].sum);
	}
}