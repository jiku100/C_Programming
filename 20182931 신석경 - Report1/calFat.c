/*******************************************************
* 파일명: calFat.c
* 프로그램 개요: 성별, 키, 몸무게를 이용하여 비만도를 출력하는 프로그램
*	표준 체중: standardWeight 함수 정의
*	비만 지수: CALFAT 매크로 정의
*   WEIGHT_PARAM_MAN: 표준 체중을 구하기 위해 남자에게 적용되는 상수 22 정의
*	WEIGHT_PARAM_WOMAN: 표준 체중을 구하기 위해 여자에게 적용되는 상수 21 정의
* 
* 
*	입력 1: 성별을 입력받는 하나의 정수
*   입력 2: 신장(키)와 몸무게를 입력 받는 두 실수
*
*   출력: 표준 체중, 비만 지수를 출력하고 그에 따른 비만도 판정 결과를 출력
*
* 날짜: 2020년 9월 11일
* 버전: 1.0
* 작성자: 20182931 신석경
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define WEIGHT_PARAM_MAN 22	// 남자 표준 체중을 구하기 위한 상수
#define WEIGHT_PARAM_WOMAN 21	// 여자 표준 체중을 구하기 위한 상수

#define CALFAT(weight, standard) ((weight / standard) * 100)	//비만도를 계산하는 매크로

float standardWeight(int op, float height);	// 표준 몸무게를 계산하는 함수

int main(void) {
	int op;	// 성별을 저장하는 변수
	float height, weight;	// 키와 몸무게를 저장하는 변수

	int n;	// 입력 성공 개수 저장 변수

	float standard, fat; // 표준 체중과 비만 지수를 저장하는 변수

	while (1) {
		printf("성별을 입력하세요. 0<종료> 1<남자>, 2<여자>: ");		// 성별 선택
		scanf("%d", &op);

		if (op == 1 || op == 2) {	// 남자 혹은 여자이면
			while (1) {
				printf("신장<cm>과 몸무게<kg>를 입력하세요: ");	// 신장과 몸무게 입력 받기
				n = scanf("%f %f", &height, &weight);	// 정확하게 들어오면 n == 2

				if (n == 2 && height > 0 && height <= 200 && weight > 0 && weight < 100) {	
					// 두 개의 입력이 신장은 0 < height < 200, 0< weight < 100 조건을 만족할 경우

					standard = standardWeight(op, height);  // 성별에 따라 표준 체중 계산
					fat = CALFAT(weight, standard);	// 비만 지수 계산

					printf(" 현재 신장: %.2f, 체중: %.2f\n", height, weight);
					printf(" 표준 체중: %.2f, 비만지수: %.2f\n", standard, fat);

					if (fat < 90)		// 10프로 미만인 경우
						printf("비만도 판정 결과 : \"체중 미달\"입니다.\n\n");
					else if (fat >= 90. && fat <= 100.)	// +- 10프로인 경우
						printf("비만도 판정 결과 : \"정상\"입니다.\n\n");
					else if (fat > 110. && fat <= 120)	// 10프로 초과 및 20프로 미만인 경우
						printf("비만도 판정 결과 : \"체중 과다\"입니다.\n\n");
					else	// 20프로 초과인 경우
						printf("비만도 판정 결과 : \"비만\"입니다.\n\n");
					break;
				}
				else {		// 다른 입력이 들어온 경우
					printf("신장 또는 몸무게를 잘못 입력 하였습니다.\n");	// 오류 출력
					while (getchar() != '\n');		// 입력 버퍼 비우기
				}
			}
		}
		else if (op == 0) {	// 종료를 원할 때
			printf("**** 프로그램을 종료합니다. **** \n\n");
			break;
		}
		else {	// 1, 2에 해당하는 옵션이 들어오지 않은 경우
			printf("성별을 잘못 입력 하였습니다.\n\n");	// 오류 출력
			while (getchar() != '\n');		// 입력 버퍼 비우기
		}
	}
	return 0;
}

float standardWeight(int op, float height) {	// 표준 몸무게를 계산하는 함수
	// 성별, 신장을 입력 받아 표준 체중을 계산
	// 성별은 무조건 1(남자) 아니면 2(여자)로 입력됨. 예외는 함수를 사용하기 전에 검사

	float height_meter = height / 100;	// cm 단위를 m로 변환하여 신장 저장
	if (op == 1) {	// 성별이 남자이면
		return height_meter * height_meter * WEIGHT_PARAM_MAN;	// 남자일 경우 표준 체중 = 신장(m) * 신장(m) * 22 계산
	}
	else {		// 성별이 여자일 경우
		return height_meter * height_meter * WEIGHT_PARAM_WOMAN; // 여자일 경우 표준 체중 = 신장(m) * 신장(m) * 21 계산
	}
}