/*
* int형 변수 value에 일정 16진수 값을 저장하고 char*로 접근하여 
* 각각 byte에 해당하는 문자를 출력하는 프로그램
*/

#include <stdio.h>

int main(void) {
	printf("int 변수에 저장되어 있는 16진수를 문자로 출력\n\n");

	int n = 0x2f24263f;	// 변수와 값 선언
	char* pc = (char*) &n;	// n을 가리키는 변수 char 포인터 선언

	printf("문자    주소값\n");

	for (int i = 0; i < 4; i++) {
		char ch = *(pc + i);	// char 포인터이기에 pc + i는 1바이트씩 이동
		printf("  %c    %p\n", ch, pc + i);
	}
	printf("\n");
	return 0;
}