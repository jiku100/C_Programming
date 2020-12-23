#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ConvertToSquareMeter(x) ((x)*3.305785) // 평 단위를 제곱미터 단위로 바꾸기 위한 매크로


/*
* 세 개의 아파트 면적의 평을 구분 문자가 포함된 표준입력으로 받아 제곱미터로 출력하는 프로그램
*/

int main(void) {
	printf("세 개의 아파트 면적을 입력 받아 제곱미터로 출력\n");
	printf("구분 문자는 /로 한다. ex. 25/31/45\n\n");		// /문자로 입력을 구분

	printf("세 개의 아파트 면적을 입력하세요.: ");
	int area1, area2, area3;
	scanf("%d/%d/%d", &area1, &area2, &area3);		// 세 개의 면적을 입력 받음.

	printf("%d평 = %f (m^2)\n", area1, ConvertToSquareMeter(area1));		// 입력된 평을 매크로를 사용해 제곱미터로 변환
	printf("%d평 = %f (m^2)\n", area2, ConvertToSquareMeter(area2));
	printf("%d평 = %f (m^2)\n", area3, ConvertToSquareMeter(area3));

	return 0;
}