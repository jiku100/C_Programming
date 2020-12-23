#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
* 부호없는 정수를 16진수로 입력 받아 최하위 바이트부터 순서대로 
* 각바이트의 값을 16진수로 출력하는 프로그램
*/


int main(void) {
	printf("부호없는 정수를 16진수로 입력 받아 최하위 바이트부터 순서대로 각바이트의 값을 16진수로 출력\n\n");

	int hex;	// 16 진수를 저장할 변수
	printf("16진수로 데이터를 입력하시오 : ");
	scanf("%x", &hex);
	for (int i = 0; i < 4; i++) {
		printf("byte %d : %x\n", i, hex & 0xff);	// & 비트 연산으로 최하위 1 byte만 결과를 가져옴
		hex = hex >> 8;		// 1 byte(8비트) 만큼 오른쪽으로 이동
	}
	return 0;
}	