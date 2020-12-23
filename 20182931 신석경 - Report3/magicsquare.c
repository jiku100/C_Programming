/*******************************************************
* 파일명: magicsquare.c
* 프로그램 개요: 마방진을 그리는 프로그램
*	마방진 세팅: magicSquare() 함수 사용
*	마방진 그리기: printSquare() 정의
*
*	입력 1: 마방진의 한 변의 길이를 나타내는 홀수 n
*
*	출력: 마방진
*
* 날짜: 2020년 11월 04일
* 버전: 1.0
* 작성자: 20182931 신석경
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void magicSquare(int** square, const int n); // 마방진 세팅 함수
void printSquare(int** square, const int n);	// 마방진 그리기 함수


int main(void) {
	int n;	// 마방진 한 변의 길이를 저장하는 변수
	printf("마방진을 구할 홀수 정수 n을 입력하세요.(n>2) n ==> ");
	while (scanf("%d", &n) != 1 || n % 2 == 0 || n < 2) {	// 올바른 입력이 들어올 때까지
		while (getchar() != '\n');
		if (n % 2 == 0)
			printf("%d은 짝수입니다. 다시 입력하시오.\n", n);
		else if (n < 2)
			printf("2 보다 큰 홀수를 입력하시오.\n");
		else
			printf("정수를 입력하시오.\n");
		printf("마방진을 구할 홀수 정수 n을 입력하세요.(n>2) n ==> ");
	}
	
	int** square = calloc(n, sizeof(int*));   
	// 이중 포인터에 (int 포인터 크기 * n)만큼 동적 메모리 할당. 행 의미

	for (int i = 0; i < n; i++)            // 행 크기만큼 반복
	{
		square[i] = calloc(n, sizeof(int));    // (int의 크기 * n)만큼 동적 메모리 할당. 열 의미
	}

	magicSquare(square, n);	// 마방진 세팅
	printSquare(square, n);	// 마방진 그리기
	return 0;
}

void magicSquare(int** square, const int n) { // 마방진 세팅 함수
	int x = n / 2;	// 처음 그릴 x 위치는 열의 가운데
	int y = 0;		// 처음 그릴 y 위치는 첫 번째 행
	int count = 1;	// 처음 그릴 숫자는 1
	while(1){	
		square[y--][x++] = count++;	
		if (count > n * n) { // 총 n * n개의 숫자를 세팅
			break;	// 모든 행렬에 값을 주면 break
		}
		// 위치에 숫자를 그리고, 오른쪽 상단으로 향하는 대각선으로 좌표 이동 count 1 증가
		if (x > n - 1 && y < 0) {	// 완전히 표를 벗어난 경우
			x -= 1;
			y += 2;
			// 바로 전 칸의 아래로 이동
		}
		if (x > n - 1) {	// x 좌표가 열의 index를 넘어가면
			x = 0;	// 0번 index로 이동
		}
		if (y < 0) {		// y 좌표가 행의 index를 -로 넘어가면
			y = n - 1;	// n-1번 index로 이동
		}
		else if (y > n - 1) {	// y 좌표가 행의 index를 +로 넘어가면
			y = 0;	// 0으로 이동
		}

		while (square[y][x] != 0) {	// 이동한 곳이 비어있지 않으면
			x -= 1;
			y += 1;
			// 원래 칸으로 이동 후
			y += 1;	// 아래 칸으로 이동
			if (y < 0) {		// y 좌표가 행의 index를 -로 넘어가면
				y = n - 1;	// n-1번 index로 이동
			}
			else if (y > n - 1) {	// y 좌표가 행의 index를 +로 넘어가면
				y = 0;	// 0으로 이동
			}
		}
	}
}

void printSquare(int** square, const int n) {	// 마방진 그리기 함수
	printf("\n n이 %d인 마방진의 결과는 다음과 같습니다.\n\n", n);
	int sum = 0;
	for (int y = 0; y < n; y++) {		// 2차원 배열을 출력하는 for문
		for (int x = 0; x < n; x++) {
			printf("%5d", square[y][x]);
			sum += square[y][x];		// y 번째 행의 원소 합을 sum으로 저장
		}
		printf("  |%5d", sum);		// y 번째 행 원소 합 출력
		sum = 0;
		printf("\n");
	}
	for (int i = 0; i < n; i++) {
		printf("  ---");
	}
	printf("\n");
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			sum += square[y][x];		// x 번째 열의 원소 합을 sum으로 저장
		}
		printf("%5d", sum);	// x 번째 열 원소 합 출력
		sum = 0;
	}
	printf("\n");
}