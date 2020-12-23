#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(void) {
	char str[64];
	char* token[64];
	char des[] = " \t";
	int sum = 0;	// 결과 값 저장
	int num1 = 0;	// 피연산자 1
	int num2 = 0;	// 피연산자 2
	int isright = 1;	// 올바른 식인지 검사하는 변수
	while (1) {
		printf("연산식을 입력하시오 >> ");
		fgets(str, 64, stdin);	// fgets로 한줄을 읽어옴
		str[strlen(str) - 1] = '\0';	// 마지막 \n을 \0으로 바꿈
		printf("%s", str);
		char* ptr = strtok(str, des);	// des에 있는 구분자로 첫 토큰 분리
		int i = 0;
		while (ptr != NULL) {	// 분리한 것이 있으면
			token[i] = ptr;	// token[i]에 저장
			ptr = strtok(NULL, des);	// 그 다음부터 토큰 분리
			i++;
		}
		token[i] = '\0';	// 토큰 분리 마지막에 NULL문자 추가
		
		i = 0;
		while (token[i]) {	// NULL문자 전까지
			if (isdigit(token[i][0])) {	// 토큰의 첫문자가 숫자이면, 이 과정은 1번째만 실행
				// 그 이유는 연산자가 입력된 이후부터는 연산자 내부에서 다음 숫자를 가져오기 때문에
				// 숫자는 연산자 if문에서 다 처리된다.
				num1 = atoi(token[i]);	// 그 토큰을 숫자로 변경
			}
			else if (strcmp(token[i], "+") == 0) {	// 문자 + 이면
				i++;	// 다음 문자로 이동
				if (isdigit(token[i][0])) {	// 그 다음 문자가 숫자이면
					num2 = atoi(token[i]);	// 숫자 바꿔서
					num1 += num2;	// 연산
				}
				else {	// 아니면 오류
					printf(" 잘못된 수식입니다.\n\n");
					isright = 0;
					break;
				}
			}
			// 나머지는 위와 비슷
			else if (strcmp(token[i], "-") == 0) {
				i++;
				if (isdigit(token[i][0])) {
					num2 = atoi(token[i]);
					num1 -= num2;
				}
				else { 
					printf(" 잘못된 수식입니다.\n\n");
					isright = 0;
					break;
				}
			}
			else if (strcmp(token[i], "*") == 0) {
				i++;
				if (isdigit(token[i][0])) {
					num2 = atoi(token[i]);
					num1 *= num2;
				}
				else {
					printf(" 잘못된 수식입니다.\n\n");
					isright = 0;
					break;
				}
			}
			else if (strcmp(token[i], "/") == 0) {
				i++;
				if (isdigit(token[i][0]) && atoi(token[i]) != 0) {	// 다음 문자가 숫자인데 0이 아닌 경우
					num2 = atoi(token[i]);
					num1 /= num2;
				}
				else {
					printf(" 잘못된 수식입니다.\n\n");
					isright = 0;
					break;
				}
			}
			else {
				printf(" 잘못된 수식입니다.\n\n");
				isright = 0;
				break;
			}
			i++;	// 다음 문자 이동
		}
		if (isright == 1) {	// 올바른 수식이면
			sum = num1;	// num1이 결과
			printf(" = %d\n\n", sum);	// 결과 출력
		}
		isright = 1;	// 초기화
		sum = num1 = num2 = 0;	// 초기화
	}
	return 0;
}