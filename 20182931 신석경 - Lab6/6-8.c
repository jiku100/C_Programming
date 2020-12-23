/*
* 두자리 정수(10~ 99) 까지의 난수(random number)를 20개 생성하여 배열에 저장하고
* 사용자가 5개의 숫자를 입력하여 몇 개를 맞추는지 검사하는 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void initRand(int* number);
void check(int* random, int* input);

int main(void) {
	int random[20] = { 0, };
	int input[5] = { 0, };
	srand((long)time(NULL));	// seed 초기화
	while (1) {
		initRand(random);
		printf("두자리수<10 ~ 99> 20개의 random number 를 생성합니다.***************************\n");
		printf("서로 다른 정수 5개<10 ~ 99>를 입력하시오 >> ");
		scanf("%d %d %d %d %d", input, input + 1, input + 2, input + 3, input + 4);	// 배열에 입력된 숫자 저장
		check(random, input);	// 난수 생성 및 확인
	}
	return 0;
}

void initRand(int* number) {	// 난수 생성 함수
	for (int i = 0; i < 20; i++) {
		number[i] = (rand() % 90) + 10;	// 10 ~ 99 사이의 숫자 20개 생성해서 number에 저장
	}
}

void check(int* random, int* input) {
	int result = 0;

	for (int i = 0; i < 20; i++) {	// random의 20개 중에 하나씩
		for (int j = 0; j < 5; j++) {	// input의 5개와 검사해서
			if (random[i] == input[j])
				result++;	// 맞으면 개수 증가
		}
	}
	printf("맞춘 개수는 %d개 입니다.\n\n", result);
}