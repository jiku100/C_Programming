/*
* cursor.c
*
* ����: �ܼ� â������ Ŀ�� �̵� �� �ܼ� Ŭ��� ���� ���
*
* include: cursor.h�� �����
*
* �Է�: ����
*
* ���: ����
*
* ���� �ڵ� ���� ��¥: 2020.11.20
* ����: 1.0
* �ۼ���: �ż���
*
*/

#include "cursor.h"
#include <stdio.h>

void gotoxy(int x, int y)	// Ŀ�� �̵� �Լ�
{
	COORD Cur;	// Ŀ�� ��ǥ�� ���� ����ü
	Cur.X = x;	// X�� ����
	Cur.Y = y;	// Y�� ����
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);	// Ŀ�� ��ġ ����
}

void console_clear() {	// ȭ�� ����� �Լ�
	system("cls");
}

void line_clear() {	// �� �� �����
	printf("                                                  ");
}