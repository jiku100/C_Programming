#include <stdio.h>

void printstr() {
	printf("software\n");
}

int main(void) {
	int a = 100;   double b = 32.83;  char* s = "string";
	void* ptr[4] = { &a, &b, s, printstr };

	printf("void * 실습 프로그램\n");
	printf("a = %d\n", *(int*)ptr[0]);
	printf("b = %f\n", *(double*)ptr[1]);
	printf("s = %s\n", (char*)ptr[2]);
	printf("printstr() 호출 : ");  ((void(*)(void))ptr[3])();
	return 0;
}