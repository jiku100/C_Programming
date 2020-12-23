#include <stdio.h>

/*
* getchar로 입력 받아 putchar로 출력, printf로 8진수, 10진수, 16진수 출력하는 프로그램
*/

int main(void) {
	printf("문자를 입력받아 문자, 8진수, 10진수, 16진수를 출력\n\n");
	printf("문자를 입력하세요: ");

	char input = getchar();		// getchar로 입력된 문자를 input에 저장

	printf("입력된 문자는: "); putchar(input); putchar('\n\n');	// 입력된 문자를 putchar를 사용해 문자로 출력
	
	printf("\n각각의 코드 값\n");
	printf("10진수: %d, 8진수: %#o, 16진수: %#x\n", input, input, input);		// 입력된 문자를 printf로 10진수, 8진수, 16진수로 출력
	return 0;
}