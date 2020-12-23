#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
* RGB의 Red, Green, Blue를 입력받아 최하위 바이트부터 차례대로 저장하고 출력하는 프로그램
*/

int main(void) {
	printf(" RGB의 Red, Green, Blue를 입력받아 최하위 바이트부터 차례대로 저장하고 출력\n\n");

	int red, green, blue; // 각각의 정보를 저장할 변수
	printf("컬러값을 차례로 입력하시오\n");
	printf("red : "); scanf("%d", &red);
	printf("green : "); scanf("%d", &green);
	printf("blue : "); scanf("%d", &blue);

	int rgb = 0;	// rgb color를 저장하는 변수;
	rgb = (rgb + blue) << 8;	// 최하위 바이트에 색상 저장하고 비트를 올림
	rgb = (rgb + green) << 8;
	rgb = (rgb + red);			// red의 경우 색상 저장만 하고 비트는 올리지 않음

	printf("RGB Color: %x\n", rgb);
	return 0;
}