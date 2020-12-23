#include <stdio.h>

int number = 1;	// 모든 파일에서 사용 가능한 number 전역 변수

void subOne(void) {
	int i = 2;	// subOne에서만 사용 가능한 i 지역 변수
	printf("i: %d\n", i);
}

void subTwo(void) {
	int j = 3;	// subTwo에서만 사용 가능한 j 지역 변수
	printf("j: %d\n", j);
}