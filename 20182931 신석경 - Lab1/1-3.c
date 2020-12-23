#include <stdio.h>

/*
* #, $, ^, &, *에 대해 문자, 8진수 코드 값, 10진수 코드 값, 16진수 코드 값 출력
* 하는 프로그램
*/
int main(void) {
	int arr[5] = { '#','$', '^','&','*' };	// 각각의 문자를 저장하는 int 형 배열 생성

	printf("각각의 문자에 대한 문자, 8진수, 10진수, 16진수 출력\n\n");
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {	// 배열의 길이만큼 for문 반복
		printf("%c: %c, %#o, %d, %#x\n", arr[i], arr[i], arr[i], arr[i], arr[i]);	// 각 문자의 문자, 8진수, 10진수, 16진수 출력
	}

	return 0;
}