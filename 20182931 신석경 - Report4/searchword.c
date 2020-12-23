/*******************************************************
* 파일명: searchword.c
* 프로그램 개요: 특정 파일 내부에 검색한 단어가 있는지 확인하는 프로그램
*	단어 검사: checkWord() 정의
*
*	입력: 검색할 단어
* 
*	출력: 검색한 단어가 포함된 줄 번호와 그 문장
*
* 날짜: 2020년 11월 24일
* 버전: 1.0
* 작성자: 20182931 신석경
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkWord(FILE* f, char* word);	// file에서 검색한 단어가 포함된 문장을 출력하는 함수

int main(int argc, char** argv) {
	if (argc < 2) {		// 넘어온 argument 개수가 2개 아래면
		printf("입력된 파일이 없습니다.\n");
		exit(1);
	}

	FILE* f;
	if ((f = fopen(argv[1], "r")) == NULL) {	// 입력된 파일을 읽기 전용으로 open
		printf("%s 파일 읽기 실패!!\n", argv[1]);
		exit(1);
	}

	char target[32];
	printf("검색에 사용될 파일은 %s 입니다.\n", argv[1]);
	printf("검색할 단어를 입력하시오 >> ");
	scanf("%s", target);		// 검색할 단어를 입력 받음

	checkWord(f, target);	// 문자가 포함된 문장 검색
	return 0;
}

void checkWord(FILE* f, char* word) {	// file에서 검색한 단어가 포함된 문장을 출력하는 함수
	printf("\n\n검색 결과 : \n\n");
	char line[1024];	// 한 줄을 읽어올 변수
	int lines = 0;		// 줄 번호를 저장할 변수
	char* temp = NULL;	// strstr 결과를 저장할 변수

	fgets(line, 1024, f);	// 한 줄을 읽어오고
	lines++;	// 줄 번호 증가
	while (!feof(f)) {
		temp = strstr(line, word);	// line에서 word로 시작하는 위치가 있는 지 검사
		if (temp != NULL) {	// 만약 시작하는 곳이 있다면
			printf("%2d :  %s", lines, line);	// 그 줄 번호와 그 줄 문장 출력
		}
		temp = NULL;	// 다시 NULL로 초기화
		fgets(line, 1024, f);	// 새로 줄 읽기
		lines++;	// 줄 번호 증가
	}
}