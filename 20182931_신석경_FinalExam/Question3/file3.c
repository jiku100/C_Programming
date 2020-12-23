#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

double vafunc(char* type, int count, ...);

int main(void) {
	int ary[] = { 15, 57, 39, 21, 32, 44 };
	vafunc("d", 5, 72, 21, 36, 43, 58);
	vafunc("f", 4, 5.8, 7.3, 2.8, 3.5, 1.9);
	vafunc("a", 6, ary);
	return 0;
}

double vafunc(char* type, int count, ...)
{
	va_list argp;	// 가변 인자 변수 선언

	va_start(argp, count);	// 가변 인자를 count 변수 뒤부터 시작
	double result = 0;
	if (strcmp(type, "d") == 0) {	// type이 "d" 이면
		printf("데이터 : ");
		float total = 0;
		int temp;
		for (int i = 0; i < count; i++) {
			temp = va_arg(argp, int);	// 정수로 가져와서
			total += temp;
			printf("%4d ", temp);	// 출력 및 저장
		}
		result = total / count;	// 최종 평균값 계산
	}
	else if (strcmp(type, "f") == 0) {	// type이 "f"이면
		printf("데이터 : ");
		float total = 0;
		float temp;
		for (int i = 0; i < count; i++) {
			temp = va_arg(argp, double);	// double로 가져와서
			total += temp;
			printf("%6.2f ", temp);	// 출력 및 저장
		}
		result = total / count;	// 최종 평균값 계산
	}
	else if (strcmp(type, "a") == 0) {	// type이 "a"이면
		printf("데이터 : ");
		int* ary = va_arg(argp, int*);	// 가변 인자로부터 int*로 가져와 배열처럼 사용
		float total = 0;
		int temp;
		for (int i = 0; i < count; i++) {
			temp = ary[i];	// 배열로써 접근
			total += temp;
			printf("%4d ", temp);	// 출력 및 저장
		}
		result = total / count;	// 최종 평균값 계산
	}
	else {
		printf("알맞은 타입이 아닙니다.");
		return 0;	// 알맞은 타입이 아니면 0 반환
	}
	printf("\n평균 %.2f\n\n", result);	// 알맞은 계산이 되면 평균값 출력
	return result;
}