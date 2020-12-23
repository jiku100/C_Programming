#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define PRINTMAX(x, y) \
		{ \
		printf("정수 "#x"와 "#y"를 입력하시오 >>"); \
		scanf("%d %d", &x, &y); \
		if(x > y)	printf(#x"와 "#y"의 최대값: %d\n", x); \
		else        printf(#x"와 "#y"의 최대값: %d\n", y); \
		}

int main(void) {
	int a, b;
	PRINTMAX(a, b);
	return 0;
}