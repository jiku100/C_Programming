/*******************************************************
* ���ϸ�: searchword.c
* ���α׷� ����: Ư�� ���� ���ο� �˻��� �ܾ �ִ��� Ȯ���ϴ� ���α׷�
*	�ܾ� �˻�: checkWord() ����
*
*	�Է�: �˻��� �ܾ�
* 
*	���: �˻��� �ܾ ���Ե� �� ��ȣ�� �� ����
*
* ��¥: 2020�� 11�� 24��
* ����: 1.0
* �ۼ���: 20182931 �ż���
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkWord(FILE* f, char* word);	// file���� �˻��� �ܾ ���Ե� ������ ����ϴ� �Լ�

int main(int argc, char** argv) {
	if (argc < 2) {		// �Ѿ�� argument ������ 2�� �Ʒ���
		printf("�Էµ� ������ �����ϴ�.\n");
		exit(1);
	}

	FILE* f;
	if ((f = fopen(argv[1], "r")) == NULL) {	// �Էµ� ������ �б� �������� open
		printf("%s ���� �б� ����!!\n", argv[1]);
		exit(1);
	}

	char target[32];
	printf("�˻��� ���� ������ %s �Դϴ�.\n", argv[1]);
	printf("�˻��� �ܾ �Է��Ͻÿ� >> ");
	scanf("%s", target);		// �˻��� �ܾ �Է� ����

	checkWord(f, target);	// ���ڰ� ���Ե� ���� �˻�
	return 0;
}

void checkWord(FILE* f, char* word) {	// file���� �˻��� �ܾ ���Ե� ������ ����ϴ� �Լ�
	printf("\n\n�˻� ��� : \n\n");
	char line[1024];	// �� ���� �о�� ����
	int lines = 0;		// �� ��ȣ�� ������ ����
	char* temp = NULL;	// strstr ����� ������ ����

	fgets(line, 1024, f);	// �� ���� �о����
	lines++;	// �� ��ȣ ����
	while (!feof(f)) {
		temp = strstr(line, word);	// line���� word�� �����ϴ� ��ġ�� �ִ� �� �˻�
		if (temp != NULL) {	// ���� �����ϴ� ���� �ִٸ�
			printf("%2d :  %s", lines, line);	// �� �� ��ȣ�� �� �� ���� ���
		}
		temp = NULL;	// �ٽ� NULL�� �ʱ�ȭ
		fgets(line, 1024, f);	// ���� �� �б�
		lines++;	// �� ��ȣ ����
	}
}