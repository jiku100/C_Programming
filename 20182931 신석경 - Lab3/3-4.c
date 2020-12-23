/*
* 정수를 입력 받아 32비트의 비트 정보를 모두 출력하는 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	printf("정수를 입력 받아 32비트로 출력\n\n");

	int num;	// 입력 저장 변수
	
	while(1){
		printf("정수를 입력하시오 >> ");
		scanf("%d", &num);
		if (num == 0)
			break;
		else {
			for (int i = 31; i >= 0; i--)	// 32개의 비트
				printf("%d", num >> i & 1);	// 하나의 비트씩 1과 &연산을 통해 알아냄
			printf("\n\n");
		}
	}
	printf("프로그램을 종료합니다.\n\n");
	return 0;
}