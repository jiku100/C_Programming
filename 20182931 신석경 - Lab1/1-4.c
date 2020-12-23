#include <stdio.h>

/*
* 문자형 연산의 결과를 문자로 출력하는 프로그램
*/

int main(void) {
	printf("문자형 연산 결과를 문자로 출력\n\n");

	printf("%c + %d의 결과: %c\n", 'A', 2, 'A' + 2);		// 'A' + 2의 결과
	printf("%c + %d의 결과: %c\n", 'A', 5, 'A' + 5);		// 'A' + 5의 결과
	printf("%c - %d의 결과: %c\n", 'S', 1, 'S' - 1);		// 'S' - 1의 결과
	printf("%c - %d의 결과: %c\n", 'S', 3, 'S' - 3);		// 'S' - 3의 결과

	return 0;
}