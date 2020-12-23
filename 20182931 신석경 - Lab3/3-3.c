/*
* 입력된 정수에서 각각의 자리에 해당하는 수를 반대로 출력하는 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
	printf("입력한 정수를 거꾸로 출력\n\n");

	int num;	// 정수 입력 변수

	printf("반대로 출력할 정수를 입력 >> ");
	scanf("%d", &num);

	printf("입력한 수를 반대로 출력 >>> ");
	while (num) {
		printf("%d", num % 10);		// 나머지 연산을 통해 거꾸로 출력가능
		num = num / 10;		// 10으로 나눠 맨 뒷자리 수를 제거
	}
	printf("\n\n");
	return 0;
}