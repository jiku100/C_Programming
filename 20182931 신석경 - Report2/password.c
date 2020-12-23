/*******************************************************
* 파일명: password.c
* 프로그램 개요: 암호를 입력받고, 암호의 안전도를 검사하는 프로그램
*	안전도 검사 : isSafe 함수 정의
*	문자열 동일성 검사 : isSameStr 함수 정의
*	문자열 길이 : mystrlen 함수 정의
*
*	입력 : 비밀번호 문자열
*
*   출력1: 안전도가 적절하지 않은 경우 그 이유 출력
*	출력2: 안전도가 정확한 경우 비밀번호 재입력하라는 문구 출력
*	출력3: 재입력한 비밀번호가 동일한 경우 비밀번호 생성 출력 및 종료
*
* 날짜: 2020년 10월 3일
* 버전: 1.0
* 작성자: 20182931 신석경
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int mystrlen(char* str);	// 문자열 길이 반환 함수
int isSafe(char* password);	// 안전도 검사 함수
int isSameStr(char* password, char* check);	// 문자열 동일성 확인 함수

int main(void) {

	char password[16];	// 비밀번호
	
	do
	{
		printf("비밀번호를 생성하시오 : ");
		scanf("%s", password);
	} while (isSafe(password) != 0);	// 적합성 검사가 정상적인 경우

	char check[16];	// 비밀번호 체크용

	do
	{
		printf("비밀번호를 재입력하시오 : ");
		scanf("%s", check);
	} while (isSafe(check) != 0 || isSameStr(password, check) != 0);// 적합성 검사, 문자열 일치 검사가 정상적인 경우

	printf("비밀번호가 정상적으로 만들어졌습니다.\n\n");
	return 0;
}

int mystrlen(char* str) {
	int n;
	for (n = 0; str[n]; n++);	// str[n]이 '\n' 혹은 NULL이 나올 때 까지
	return n;
}

int isSafe(char* password) {
	int n = mystrlen(password);	// 문자열 길이 저장 변수

	int conditions[] = { 0,0,0,0 };	// 각각 숫자, 소문자, 대문자, 특수문자 개수를 나타냄.

	for (int i = 0; i < n; i++) {
		if (password[i] >= '0' && password[i] <= '9') conditions[0]++;	// 숫자면 0번 index 1 증가
		else if (password[i] >= 'a' && password[i] <= 'z')	conditions[1]++;	// 소문자 -> 1번 index 1 증가
		else if (password[i] >= 'A' && password[i] <= 'Z')	conditions[2]++;	// 대문자 -> 2번 index 1 증가
		else	conditions[3]++;	// 특수문자의 경우 3번 index 1 증가
	}

	int checkSafe = 0;

	for (int i = 0; i < 4; i++) {
		if (conditions[i] > 0)	checkSafe++;	// 각각의 조건마다 1개 이상이 있을 경우 cheackSafe 1 증가
	}

	if (n < 8) {		// 글자 수가 8자 미만
		printf(" >> 비밀번호는 8자 이상이어야 합니다.\n");
		return -1;
	}
	else if (n > 12) {	// 글자 수가 12자 초과
		printf(" >> 비밀번호는 12자 이하여야 합니다.\n");
		return -1;
	}
	else if (checkSafe < 3) {	// 비밀번호가 대문자, 소문자, 숫자, 특수문자 중 3가지 미만을 포함하는 경우
		printf(" >> 비밀번호는 숫자, 소문자, 대문자, 특수문자 중 3가지 이상이 포함되어야 합니다.\n");
		return -1;
	}	
	return 0;
}

int isSameStr(char* password, char* check) {
	int p_len = mystrlen(password);	// password 길이
	int c_len = mystrlen(check);	// 재입력 문자열 길이

	if (p_len != c_len) {	// 문자열 길이가 다르면
		printf("비밀번호가 서로 다릅니다.\n");
		return -1;
	}

	for (int i = 0; i < p_len; i++) {
		if (password[i] != check[i]) {		// 두 문자가 다르면
			printf("비밀번호가 서로 다릅니다.\n");
			return -1;
		}
	}
	return 0;
}