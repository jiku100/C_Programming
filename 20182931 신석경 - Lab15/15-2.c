#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define PRINTXY(x, y) \
		{ \
		printf("���� "#x"�� "#y"�� �Է��Ͻÿ� >>"); \
		scanf("%d %d", &x, &y); \
		printf(#x"�� "#y"�� ���� %d�Դϴ�.\n", (x)*(y)); \
		}

int main(void) {
	int a, b;
	PRINTXY(a, b);
	return 0;
}