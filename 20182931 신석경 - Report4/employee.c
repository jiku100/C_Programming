/*******************************************************
* 파일명: employee.c
* 프로그램 개요: 회사 사원의 정보를 관리하는 프로그램
*	구조체 1: 사람을 나타내는 person 구조체
*   구조체 2: 사원을 나타내는 employee 구조체

*	사원 출력: print() 정의
*	연봉 계산: calYearMoney() 정의
*
*	입력 1: 사번 혹은 이름과 새로운 인센티브
*
*	출력: 각 사원들의 사번, 이름, 전화번호, 월급, 인센티브, 연봉
*
* 날짜: 2020년 11월 24일
* 버전: 1.0
* 작성자: 20182931 신석경
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct person {
	char name[16];	// 이름 저장
	char phonenumber[14];	// 핸드폰 번호 저장
};

struct employee {
	char id[10];	// 사번 저장
	int money;	// 월급
	int raise;	// 인센티브
	struct person p;	// 사람에 대한 정보를 가지는 변수
};

void print(struct employee* emp);	// 사원 정보 출력
int calYearMoney(struct employee emp);	// 연봉을 계산하는 함수

int main(void) {
	struct employee employees[4] = {	// 초기 사원 정보
		{"20123478", 1200000, 120, {"김지혜", "011-1111-1111"}},
		{"20123479", 1500000, 150, {"김자경", "011-2222-2456"}},
		{"20123480", 1800000, 180, {"강동구", "011-3333-2456"}},
		{"20123481", 2200000, 250, {"안태용", "017-2222-2456"}}
	};

	char target[20];	// 바꿀 사원의 이름 혹은 사번
	int raise;			// 바꿀 인센티브

	while (1) {
		print(employees);	// 모든 사원의 정보 출력
		printf("\n인센티브를 변경합니다...\n");
		printf("사번 또는 이름과 새로운 인센티브를 입력하시오 >> ");
		scanf("%s %d", target, &raise);	// 사번 혹은 이름과 인센티브를 입력받음

		for (int i = 0; i < 4; i++) {
			// 이름이 target과 같거나, 사번이 target과 같은 경우
			if (strcmp(employees[i].id, target) == 0 || strcmp(employees[i].p.name, target) == 0) {
				employees[i].raise = raise;	// 그 사원의 인센티브를 바꿈
			}
		}
	}
	return 0;
}

void print(struct employee* emp) {
	printf("\n   사번   이 름     전화번호     월급    인센티브    연봉\n");
	printf("------------------------------------------------------------\n");
	for (int i = 0; i < 4; i++) {
		// 각 사원의 사번, 이름, 전화번호, 월급, 인센티브, 연봉을 출력
		printf("%s  %s  %s  %d   %d%%   %d\n", emp[i].id, emp[i].p.name, emp[i].p.phonenumber, emp[i].money, emp[i].raise, calYearMoney(emp[i]));
	}
}

int calYearMoney(struct employee emp) {
	// 과제 파일에서는 int 연산만 계산하여 동일하게 진행함.
	return emp.money * (12 + emp.raise / 100);
}