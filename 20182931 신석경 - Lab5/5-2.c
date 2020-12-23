/*
* 입력한 온도 마지막에 문자 F나 f이면 입력 받은 값을 화씨온도로 간주하여 섭씨온도로 바꾸고, 
* 입력 받은 문자가 C나 c이면 입력 받은 값을 섭씨온도로 간주하여 화씨온도로 바꾸어 결과를 출력하는 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define to_F(C) ((9/5.) * C + 32)	// 화씨 변화 매크로
#define to_C(F) ((5/9.) * (F - 32))	// 섭씨 변화 매크로


int main(void) {
	printf("입력한 온도를 변환합니다.\n\n");
	
	double number;	// 숫자 저장 변수
	char input[128];	// 입력된 문자열을 저장하기 위한 배열
	char* pos = NULL;
	while (1) {
		printf("온도를 마지막에 F,f,C,c를 붙여서 입력하시오\n");
		printf("온도입력<예: 30.4c, 45.3f> >> ");
		scanf("%s", input);
		number = strtod(input, &pos);		// 입력된 문자열에서 double형 숫자를 반환하고 그 이후의 위치를 pos에 저장
		if (strcmp(pos, "F") == 0 || strcmp(pos, "f") == 0) {
			printf(" 화씨 온도 %.2f는 섭씨 온도로 %.2f입니다.\n\n", number, to_C(number));
		}
		else if (strcmp(pos, "C") == 0 || strcmp(pos, "c") == 0) {
			printf(" 섭씨 온도 %.2f는 화씨 온도로 %.2f입니다.\n\n", number, to_F(number));
		}
		else {
			printf("\n잘못된 문자를 입력했습니다.\n\n");
			while (getchar() != '\n');
		}
	}

}