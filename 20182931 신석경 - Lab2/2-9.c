#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
* 1사분기: 1, 2, 3월, 2사분기: 4, 5, 6월, 3사분기: 7, 8, 9월, 4사분기: 10, 11, 12월
* 위를 참고하여 입력 받은 월에 해당되는 분기를 출력하는 프로그램
*/

int main(void) {
	printf("입력 받은 월에 해당되는 분기를 출력. 단, if 문 사용\n\n");

	int month;	// 입력을 저장할 변수;
	
	printf("월(month)를 입력하세요. : ");
	scanf("%d", &month);

	int quarter; // 몇 분기 인지 저장할 변수

	if (month < 4)
		quarter = 1;
	else if (month >= 4 && month < 7)
		quarter = 2;
	else if (month >= 7 && month < 10)
		quarter = 3;
	else
		quarter = 4;
	
	printf("%d 월은 %d 사분기 입니다.\n", month, quarter);
	return 0;
		
}