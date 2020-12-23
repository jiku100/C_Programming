#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
* 두 실수를 입력 받아 사각형, 삼각형 면적을 전체 폭 12, 소수 이하 3자리 우측, 좌측 정렬로
* 출력하는 프로그램
*/

int main(void) {
	printf("두 실수를 입력 받아 사각형, 삼각형 면적 출력\n\n");

	float width, height; // 가로 세로 길이를 저장할 변수 생성
	printf("가로를 입력하세요: ");
	scanf("%f", &width);
	printf("세로를 입력하세요: ");
	scanf("%f", &height);

	printf("\n사각형의 면적: %12.3f\n", width * height);	// 전체 폭 12, 소수 이하 3자리 우측 정렬로 사각형 면적 출력
	printf("삼각형의 면적: %-12.3f\n", 0.5 * width * height);		// 전체 폭 12, 소수 이하 3자리 좌측 정렬로 삼각형 면적 출력
	return 0;
}