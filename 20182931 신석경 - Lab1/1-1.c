#include <stdio.h>

/*
* 각각의 주어진 범위 안의 수를 문자로 출력하는 프로그램
*/
int main(void) {
	printf("8진수 출력\n");
	for (int i = 041; i < 046; i++) {	// 041 ~ 045 까지 8진수를 문자로 출력
		printf("%c ", i);
	}

	printf("\n\n16진수 출력\n");
	for (int i = 0x41; i < 0x46; i++) {	// 0x41 ~ 0x45 까지 16진수를 문자로 출력
		printf("%c ", i);
	}

	printf("\n\n10진수 출력\n");
	for (int i = 97; i < 102; i++) {	// 97 ~ 101 까지 10진수를 문자로 출력
		printf("%c ", i);
	}
	return 0;
}