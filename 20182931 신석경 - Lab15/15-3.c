#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define PRINTMAX(x, y) \
		{ \
		printf("���� "#x"�� "#y"�� �Է��Ͻÿ� >>"); \
		scanf("%d %d", &x, &y); \
		if(x > y)	printf(#x"�� "#y"�� �ִ밪: %d\n", x); \
		else        printf(#x"�� "#y"�� �ִ밪: %d\n", y); \
		}

int main(void) {
	int a, b;
	PRINTMAX(a, b);
	return 0;
}