/*
* cursor.c
*
* 개요: 콘솔 창에서의 커서 이동 및 콘솔 클리어를 위한 모듈
*
* include: cursor.h를 사용함
*
* 입력: 없음
*
* 출력: 없음
*
* 최종 코드 수정 날짜: 2020.11.20
* 버전: 1.0
* 작성자: 신석경
*
*/

#include "cursor.h"
#include <stdio.h>

void gotoxy(int x, int y)	// 커서 이동 함수
{
	COORD Cur;	// 커서 좌표계 관련 구조체
	Cur.X = x;	// X값 설정
	Cur.Y = y;	// Y값 설정
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);	// 커서 위치 조정
}

void console_clear() {	// 화면 지우기 함수
	system("cls");
}

void line_clear() {	// 한 줄 지우기
	printf("                                                  ");
}