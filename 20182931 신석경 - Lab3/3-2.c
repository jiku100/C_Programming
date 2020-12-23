/*
* 1 ~ 100 까지의 수에서 소수를 찾는 프로그램
*/

#include <stdio.h>

int main(void) {
	printf("1부터 100까지의 소수 출력\n\n");

	// 에라토스테네스의 체 알고리즘 사용

	int arr[101];	// 0까지 포함한 101개의 정수 배열 선언
	for (int i = 0; i < 101; i++)
		arr[i] = i;	// 배열을 0 ~ 100으로 초기화

	for (int i = 0; i < 101; i++) {	// 에라토스테네스의 체 실행
		if (arr[i] == 1) {
			arr[i] = 0;	// 0과 1인 경우 제외
			continue;
		}
		else if (arr[i] == 0)	// 이미 제외된 경우
			continue;
		else {	// 제외되지 않은 경우
			printf("%d ", arr[i]);
			for (int j = 2 * i; j < 101; j = j + i) {	// arr[i]의 배수를 다 0으로 바꿈
				arr[j] = 0;
			}
		}
	}
	printf("\n");
	return 0;
}