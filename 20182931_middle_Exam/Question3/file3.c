#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
	int pascal[][10] = { 0, };
	int target;
	while (1) {
		printf("파스칼의 삼각형의 크기를 입력하시오 >> ");
		scanf("%d", &target);
		if (!(target > 0 && target < 11)) {
			printf(" ?? 삼각형의 크기는 10 이하의 양의 정수이어야 합니다.\n\n");
			continue;
		}
		
		for (int n = 0; n < target; n++) {	// target행 전까지
			for (int r = 0; r <= n; r++) {
				pascal[n][r] = 1; // 행의 첫 원소는 1로 초기화
				for (int i = 1; i <= n; i++) {
					pascal[n][r] *= i;	// n! 계산
				}
				for (int i = 1; i <= r; i++) {
					pascal[n][r] /= i;	// r!으로 나누는 거 계산
				}
				for (int i = 1; i <= (n - r); i++) {
					pascal[n][r] /= i;	// (n-r)!으로 나누는 거 계산
				}
			}
		}


		for (int n = 0; n < target; n++) {
			for (int r = 0; r <= n; r++) {
				printf("%d  ", pascal[n][r]);	// 각 원소 출력
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}