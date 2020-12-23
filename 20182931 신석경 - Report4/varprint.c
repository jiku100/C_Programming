/*******************************************************
* 파일명: varprint.c
* 프로그램 개요: 정수, 문자, 정수 배열, 문자열을 출력할 수 있는 함수 정의
*	자료 출력: printItems() 정의
*	각 타입 확인: DTPYE 열거형 정의
* 
*	출력: 각 상황에 맞는 값 출력
*
* 날짜: 2020년 11월 24일
* 버전: 1.0
* 작성자: 20182931 신석경
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

enum DTYPE { INT, CHAR, INTARY, CHARSTR };
void printItems(void* p, int size, int datatype); // p에 넘어온 자료를 출력하는 함수


int main(void) {
	int ary[10] = { 1,2,3,4,5,6,7,8,9,10 };
	char* str = "abcdef";

	printItems((void*)ary, 0, INT); // INT일 때는 size 값은 상관없음
	printItems((void*)str, 0, CHAR);// CHAR일 때도 size 값은 상관없음
	printItems((void*)ary, sizeof(ary)/sizeof(int), INTARY);	// INTARY로 넘어갈 때는 size를 넘겨줘야함
	printItems((void*)str, strlen(str), CHARSTR);	// CHARARY로 넘어갈 때도 길이를 구해야함.
	return 0;
}

void printItems(void* p, int size, int datatype) { // p에 넘어온 자료를 출력하는 함수
	int* ary = NULL;	// int* 초기화
	char* str = NULL;	// char* 초기화
	switch (datatype)
	{
	case INT:	// datatype이 INT라면
		ary = (int*)p;	// void*를 int*로 바꿔서
		printf("ary[0] = %d\n", *ary);	// 첫 원소만 출력
		break;
	case CHAR:	// datatype이 CHAR라면
		str = (char*)p;	// void*를 char*로 바꿔서
		printf("*str = %c\n", *str);	// 첫 원소만 출력
		break;
	case INTARY:	// datatype이 INTARY라면
		ary = (int*)p;	// void*를 int*로 받아서
		printf("ary = ");
		for (int i = 0; i < size; i++) {	// size 개수만큼 출력
			if (i < size - 1)
				printf("%d, ", ary[i]);
			else
				printf("%d\n", ary[i]);
		}
		break;
	case CHARSTR:	// datatype이 CHARARY라면
		str = (char*)p;	// void*를 char*로 받아서
		printf("str = ");
		for (int i = 0; i < size; i++) {	// size 개수만큼 출력
			if (i < size - 1)
				printf("%c, ", str[i]);
			else
				printf("%c\n", str[i]);
		}
	default:
		break;
	}
}