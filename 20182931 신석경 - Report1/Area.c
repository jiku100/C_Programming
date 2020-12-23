/*******************************************************
* 파일명: Area.c
* 프로그램 개요: 도형의 면적을 계산하는 프로그램( 삼각형, 정사각형, 사각형, 원 )
*	삼각형 넓이: triangle 함수 정의
*	정사각형 넓이: square 함수 정의
*   사각형 넓이: rectangle 함수 정의
*   원 넓이: circle 함수 정의
*	PI: 3.141592로 정의
* 
*	입력 1: 정수 한개, 도형을 선택하는 입력
*   입력 2: 각각의 도형에 필요한 정보를 입력 받는 두 실수
* 
*   출력: 각 도형에 해당되는 넓이
* 
* 날짜: 2020년 9월 11일
* 버전: 1.0
* 작성자: 20182931 신석경
* 
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define PI 3.141592		// 원주율 정의
float triangle(float width, float height); // 삼각형 넓이 계산 함수
float square(float length);	// 정사각형 넓이 계산 함수
float rectangle(float width, float height); // 사각형 넓이 계산 함수
float circle(float radius);	// 원 계산 함수

int main(void) {
	int op;		// 선택 옵션 저장 변수
	float input1, input2;	// 입력 받을 두 변수
	int n;	// 입력 성공 개수 저장 변수
	float result; // 계산 결과를 저장하는 변수

	while (1) {
		printf("삼각형[1] 정사각형[2] 사각형[3] 원[4] 프로그램 종료[5]\n");		// 옵션 공지
		printf("면적을 구할 도형의 번호를 선택하세요. >> ");
		scanf("%d", &op);		// 넓이를 계산할 도형 선택 옵션 저장

		/* 
		* if문을 선택한 이유는 switch 문을 사용할 경우 5번을 선택할 때에
		* break문을 두번 사용하여야 프로그램을 종료할 수 있기 때문에 if문을 사용함
		*/

		if (op == 1) {	// 삼각형을 선택한 경우
			while (1) {		// 계산이 완료될 때까지 반복
				printf("삼각형의 면적을 구합니다. 가로와 높이를 실수로 입력하세요. >> ");
				n = scanf("%f %f", &input1, &input2);	// 실수 2개 입력 받기
				if (n == 2) {		// 입력이 2개의 실수로 올바르게 들어온 경우
					result = triangle(input1, input2);		// 넓이 계산 결과를 result에 저장
					printf("[ 결과 ] 가로: %.2f, 높이: %.2f, 삼각형 면적: %.2f\n\n", input1, input2, result);	// 결과 출력
					break;
				}
				else {	// 실수 2개가 아닌 다른 입력이 들어온 경우
					printf("?? 가로 또는 높이 입력 오류\n");	// 오류 출력
					while (getchar() != '\n');		// 입력 버퍼 비우기
				}
			}
		}
		else if (op == 2) {	// 정사각형을 선택한 경우
			while (1) {		// 계산이 완료될 때까지 반복
				printf("정사각형의 면적을 구합니다. 한 변 길이를 실수로 입력하세요. >> ");
				n = scanf("%f", &input1);		// 실수 1개 입력 받기
				if (n == 1) {
					result = square(input1);	// 넓이 계산 결과를 result에 저장
					printf("[ 결과 ] 한 변 길이: %.2f, 정사각형 면적: %.2f\n\n", input1, result);	// 결과 출력
					break;
				}
				else {	// 실수 1개가 아닌 다른 입력이 들어온 경우
					printf("?? 한 변 길이 입력 오류\n");	// 오류 출력
					while (getchar() != '\n');		// 입력 버퍼 비우기
				}
			}
		}
		else if (op == 3) {	// 사각형을 선택한 경우
			while (1) {		// 계산이 완료될 때까지 반복
				printf("사각형의 면적을 구합니다. 가로와 세로를 길이를 실수로 입력하세요. >> ");
				n = scanf("%f %f", &input1, &input2);	// 실수 2개 입력 받기
				if (n == 2) {		// 입력이 2개의 실수로 올바르게 들어온 경우
					result = rectangle(input1, input2);		// 넓이 계산 결과를 result에 저장
					printf("[ 결과 ] 가로: %.2f, 높이: %.2f, 사각형 면적: %.2f\n\n", input1, input2, result);	// 결과 출력
					break;
				}
				else {	// 실수 2개가 아닌 다른 입력이 들어온 경우
					printf("?? 가로 또는 높이 입력 오류\n");	// 오류 출력
					while (getchar() != '\n');		// 입력 버퍼 비우기
				}
			}
		}
		else if (op == 4) {	// 원을 선택한 경우
			while (1) {		// 계산이 완료될 때까지 반복
				printf("원의 면적을 구합니다. 반지름 길이를 실수로 입력하세요. >> ");
				n = scanf("%f", &input1);	// 실수 1개 입력 받기
				if (n == 1) {		// 입력이 1개의 실수로 올바르게 들어온 경우
					result = circle(input1);		// 넓이 계산 결과를 result에 저장
					printf("[ 결과 ] 반지름: %.2f, 원 면적: %.2f\n\n", input1, result);	// 결과 출력
					break;
				}
				else {	// 실수 1개가 아닌 다른 입력이 들어온 경우
					printf("?? 반지름 길이 입력 오류\n");	// 오류 출력
					while (getchar() != '\n');		// 입력 버퍼 비우기
				}
			}
		}
		else if (op == 5) {		// 프로그램 종료 선택
			printf("**** 프로그램을 종료합니다. **** \n\n");
			break;
		}
		else {	// 1 ~ 5에 해당하는 옵션이 들어오지 않은 경우
			printf("?? 번호 선택이 잘못되었습니다.\n\n");	// 오류 출력
			while (getchar() != '\n');		// 입력 버퍼 비우기
		}
	}
	return 0;
}

float triangle(float width, float height) { // 삼각형 넓이 계산 함수
	// 가로 세로를 입력 받아 삼각형 넓이 계산
	return 0.5 * width * height;	// 삼각형 넓이 계산
}
float square(float length) {	// 정사각형 넓이 계산 함수
	// 한 변의 길이를 입력 받아 정사각형 넓이 계산
	return length * length;	 // 정사각형 넓이 계산
}
float rectangle(float width, float height) { // 사각형 넓이 계산 함수
	// 가로 세로를 입력 받아 사각형 넓이 계산
	return width * height;	// 사각형 넓이 계산
}
float circle(float radius) {	// 원 계산 함수
	// 반지름을 입력 받아 원 넓이 계산
	return PI * radius * radius;	// 원의 넓이 계산, PI는 header에 정의
}