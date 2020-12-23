#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int check_num(char* str1, char* str2);
int check_op(char* str);

int main(int argc, char* argv[]) {
	if (argc < 4) {
		printf(" ?? 잘못된 연산식입니다.\n\n");
		return 0;
	}
	else {
		int num1;
		int num2;
		int result;
		if (check_num(argv[1], argv[3]) == 0) {	// 주어진 입력이 숫자이면
			num1 = atoi(argv[1]); // 첫번째 인자 숫자로 변경
			num2 = atoi(argv[3]);	// 두번째 인자 숫자로 변경
		}
		else {
			printf(" ?? 피연산자가 정수가 아닙니다.\n\n");
			return 0;	//프로그램 종료
		}
		
		if (check_op(argv[2]) == 0) {
			if (strcmp(argv[2], "+") == 0) {	// + 연산이면
				result = num1 + num2;
				printf("%d %s %d = %d\n\n", num1, argv[2], num2, result);
			}
			else if (strcmp(argv[2], "-") == 0) {	// - 연산이면
				result = num1 - num2;
				printf("%d %s %d = %d\n\n", num1, argv[2], num2, result);
			}
			else if (strcmp(argv[2], "*") == 0) {	// * 연산이면
				result = num1 * num2;
				printf("%d %s %d = %d\n\n", num1, argv[2], num2, result);
			}
			else if (strcmp(argv[2], "/") == 0) {	// / 연산이면
				if (num2 == 0) {	// 뒤에 피연산자가 0이면
					result = 0;	// 결과 0
				}
				else {
					result = num1 / num2;	// 아니면 연산
				}
				printf("%d %s %d = %d\n\n", num1, argv[2], num2, result);
			}
		}
		else {
			printf(" ?? 잘못된 연산자입니다.\n\n");
			return 0;
		}
	}
	return 0;
}

int check_num(char* str1, char* str2) {
	// str1이 숫자로만 이루어져있는지 확인
	int n = strlen(str1);
	for (int i = 0; i < n; i++) {
		if(!isdigit(str1[i]))
			return -1;
	}
	// str2가 숫자로만 이루어져있는지 확인
	n = strlen(str2);
	for (int i = 0; i < n; i++) {
		if (!isdigit(str2[i]))
			return -1;
	}
	return 0;
}

int check_op(char* str) {
	// 사칙 연산 종류일 경우 0 return 아니면 -1
	if (strcmp(str, "+") == 0);
	else if (strcmp(str, "-") == 0);
	else if (strcmp(str, "*") == 0);
	else if (strcmp(str, "/") == 0);
	else {
		return -1;
	}
	return 0;
}