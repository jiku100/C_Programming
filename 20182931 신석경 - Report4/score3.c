/*******************************************************
* 파일명: score3.c
* 프로그램 개요: in.txt에서 구조체를 읽어 각 학생의 점수의 합을 구하여 출력하고 out.txt파일에 저장
*	점수 합계: calSum() 계산
*	출력 파일 쓰기 및 출력: printOut() 정의
*
*	출력: 각 학생들의 정보
*
* 날짜: 2020년 11월 24일
* 버전: 1.0
* 작성자: 20182931 신석경
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct student {
	int order;
	char name[16];
	float score1;
	float score2;
	float sum;
};
typedef struct student student;

void calSum(student* st, int number);	// 점수 합 계산 함수
void printOut(FILE* out, student* st, int number);	// 학생 구조체의 정보를 out file에 출력하는 함수

int main(void) {
	FILE* in, * out;	// in, out stream

	if ((in = fopen("in.txt", "r")) == NULL) {	// in.txt 를 읽기 전용으로 열음
		printf("in.txt 파일을 읽을 수 없습니다.\n");
		exit(1);
	}

	if ((out = fopen("out.txt", "w")) == NULL) {	// out.txt 를 쓰기 전용으로 열음
		printf("out.txt 파일을 열 수 없습니다.\n");
		exit(1);
	}

	char line[80];	// 한 줄을 읽어올 변수
	int cnt = 0;	// 순번을 저장할 변수
	student st[10];	// 10명의 학생을 저장할 수 있는 구조체 배열 선언

	while (!feof(in)) {
		fgets(line, 80, in);	// in에서 한 줄을 읽어옴
		// 아래의 형식대로 in.txt에서 구조체 정보를 분리함
		sscanf(line, "%d    %s    %f    %f", &st[cnt].order, st[cnt].name, &st[cnt].score1, &st[cnt].score2);
		cnt++;
	}

	printf("--------------------------------------------\n");
	printf("%5s%8s%10s%8s%10s\n", "번호", "이름", "과목1", "과목2", "합계");
	printf("============================================\n");
	calSum(st, cnt);	// 각 학생들의 성적 합을 계산하여 st.sum에 저장
	printOut(out, st, cnt);	// 각 학생들의 정보를 화면에 출력 및 out.txt에 저장
	printf("--------------------------------------------\n");

	fclose(in);
	fclose(out);
	return 0;


}
void calSum(student* st, int number) {
	for (int i = 0; i < number; i++) {	// number 명의 각 학생들의 점수 합계를 계산하여 저장
		st[i].sum = (st[i].score1 + st[i].score2);
	}
}

void printOut(FILE* out, student* st, int number) {
	for (int i = 0; i < number; i++) {
		// 각 st의 정보를 형식에 맞춰서 out에 저장
		fprintf(out, "%d    %s    %.1f    %.1f    %.1f\n", st[i].order, st[i].name, st[i].score1, st[i].score2, st[i].sum);
		// 화면에 출력
		printf("%3d%12s%8.1f%8.1f%10.1f\n", st[i].order, st[i].name, st[i].score1, st[i].score2, st[i].sum);
	}
}