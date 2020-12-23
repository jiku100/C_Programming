#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define PRINTXY(x, y) \
		{ \
		printf("정수 "#x"와 "#y"를 입력하시오 >>"); \
		scanf("%d %d", &x, &y); \
		printf(#x"와 "#y"의 곱은 %d입니다.\n", (x)*(y)); \
		}

int main(void) {
	int a, b;
	PRINTXY(a, b);
	return 0;
}