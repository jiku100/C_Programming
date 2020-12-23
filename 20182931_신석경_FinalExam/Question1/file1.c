#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int numerator;
	int denominator;
} fraction;		// 구조체 정의

fraction* add(fraction* f1, fraction* f2);
fraction* sub(fraction* f1, fraction* f2);
fraction* mul(fraction* f1, fraction* f2);
fraction* divide(fraction* f1, fraction* f2);
// 각각의 연산 함수 정의
int main(void) {
	fraction* f1, *f2;	// 연산할 구조체 변수 정의
	fraction* result = NULL;	// 결과 구조체 정의
	int input1, input2;
	char op;
	char line[1024];
	char* ptr = NULL;
	f1 = calloc(0, sizeof(fraction));	// 동적 할당
	f2 = calloc(0, sizeof(fraction));	// 동적 할당
	int fail = 0;
	int i = 0;
	do
	{
		printf("분수의 연산식을 입력하시오 >> ");
		fgets(line, 1024, stdin);	// 문자식 입력 받아
		ptr = strtok(line, "\t ");	// 공백과 \t으로 토큰 분리
		i = 0;	// 어떤 연산을 실행할지 결정
		while (ptr != NULL)
		{
			if (i == 0) {	// i == 0이면 첫 토큰 의미 -> 1/2 와 같은 분수
				sscanf(ptr, "%d/%d", &input1, &input2);
				f1->numerator = input1;	// f1에 저장
				f1->denominator = input2;
				i++;
			}
			else if (i == 1) {	// i == 1이면 연산자 의미
				if (strcmp(ptr, "+") == 0 || strcmp(ptr, "-") == 0 || strcmp(ptr, "*") == 0 || strcmp(ptr, "/") == 0) {
					op = *ptr;
					i++;
				}
				else {	// 해당되는 연산자가 아닌 경우 오류 출력 및 돌아감
					printf("연산자 오류\n");
					fail = 1;
					break;
				}
			}
			else if (i == 2) {	// i == 2인 경우 3번째 토큰 의미 -> 2/3 와 같은 분수
				sscanf(ptr, "%d/%d", &input1, &input2);
				f2->numerator = input1;
				f2->denominator = input2;	// f2에 저장
				i++;
			}
			else {	// 더 초과된 경우 오류
				printf("입력 초과\n");
				fail = 1;
				break;
			}
			ptr = strtok(NULL, "\t ");
		}
		if (!fail) {	// 실패하지 않았으면, 즉 올바른 분수 및 연산자 입력이면 연산 수행 결과 result에 저장
			if (op == '+') {
				result = add(f1, f2);
			}
			else if (op == '-') {
				result = sub(f1, f2);
			}
			else if (op == '*') {
				result = mul(f1, f2);
			}
			else if (op == '/') {
				result = divide(f1, f2);
			}

			printf(" = %d/%d\n", result->numerator, result->denominator);	// result에 할당된 값 출력
		}
		fail = 0;	// 초기화
		i = 0;		// 초기화
	} while (1);

	return 0;
}

fraction* add(fraction* f1, fraction* f2) {
	fraction* result = calloc(1, sizeof(fraction));

	result->numerator = f1->numerator * f2->denominator + f2->numerator * f1->denominator;
	result->denominator = f1->denominator * f2->denominator;
	return result;
}
fraction* sub(fraction* f1, fraction* f2) {
	fraction* result = calloc(1, sizeof(fraction));

	result->numerator = f1->numerator * f2->denominator - f2->numerator * f1->denominator;
	result->denominator = f1->denominator * f2->denominator;
	return result;
}
fraction* mul(fraction* f1, fraction* f2) {
	fraction* result = calloc(1, sizeof(fraction));

	result->numerator = f1->numerator * f2->numerator;
	result->denominator = f1->denominator * f2->denominator;
	return result;
}
fraction* divide(fraction* f1, fraction* f2) {
	fraction* result = calloc(1, sizeof(fraction));

	result->numerator = f1->numerator * f2->denominator;
	result->denominator = f1->denominator * f2->numerator;
	return result;
}