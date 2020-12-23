#include <stdio.h>

extern int number;		// 9-1_sub.c에 정의된 number -> 1
static double data = 4;	// 9-1.c에서만 사용 가능한 data 정적 전역 변수

void function(void);
int main(void) {
	register int count = 5;	// main 함수에서만 사용 가능한 count 레지스터 지역 변수

	printf("number: %d\n", number);	// 9-1_sub.c에 선언된 number 출력
	subOne();	// 외부 파일 함수
	subTwo();	// 외부 파일 함수
	printf("data: %lf\n", data);		// 이 파일에서만 정의된 data 출력
	printf("count: %d\n", count);	// main scope에 선언된 count 출력
	function();	// 이 file에서 정의된 함수
	
	return 0;
}

void function(void) {
	static int amount = 6;	// function scope에서만 사용 가능한 amount 정적 지역 변수 
	printf("amount: %d\n", amount);
}