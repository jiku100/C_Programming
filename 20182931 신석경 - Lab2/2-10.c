#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define False 0
#define True 1
/*
* 입력 받은 년도와 달을 이용해 월의 말일을 출력하는 프로그램
*/


int main(void) {
	printf("년과 월을 입력하면 그 달의 말일을 알려드립니다.\n\n");

	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };	// 각 달의 일 수를 저장한 배열

	int year, month;	// 입력 받을 년도와 달을 저장할 변수
	printf("입력(예: 2020 2) >> ");
	scanf("%d %d", &year, &month);

	int isLeap = False;

	if (year % 400 == 0)		// 400으로 나누어 떨어지면 윤년
		isLeap = True;
	else if (year % 4 == 0) {	// 일단 4로 나누어 지면
		isLeap = True;	// 일단 윤년으로 설정
		if (year % 100 == 0)	// 4로 나누어 떨어지고 100으로도 나누어 떨어지면 (400은 위 if문에서 제외됨)
			isLeap = False;
	}

	if (isLeap)		// 윤년이면
		days[1] = 29;	// 2월 달을 29일로 바꿈

	printf("%d년 %d월의 말일은 %d일입니다.\n", year, month, days[month - 1]);
	return 0;
}