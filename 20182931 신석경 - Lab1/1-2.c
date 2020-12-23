#include <stdio.h>
#define ConvertToSquareMeter(x) ((x)*3.305785) // 평 단위를 제곱미터 단위로 바꾸기 위한 매크로

/*
* 입력된 평 단위에 대해 제곱미터 단위로 변환하여 출력하는 프로그램
*/
int main(void) {
	int area[5] = { 18, 25, 32, 44, 52 };	// 각각의 평 면적을 배열로 저장

	printf("각각의 평에 대한 제곱미터 면적\n\n");

	for (int i = 0; i < sizeof(area) / sizeof(int); i++) {	// 평 면적 배열의 크기만큼 배열 반복
		printf("%d평의 제곱미터: %f (m^2)\n", area[i], ConvertToSquareMeter(area[i]));	// 각각의 평에 대한 제곱미터 단위 출력
	}
	return 0;
}