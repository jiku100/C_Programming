#ifndef CURSOR
#define CURSOR


#include <windows.h>

void gotoxy(int x, int y);	// 커서 이동 함수
void console_clear();	// 화면 지우기 함수
void line_clear();	// 한 줄 지우기

#endif // !CURSOR