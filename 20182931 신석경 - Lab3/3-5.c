/*
* 두개의 16진수를 입력으로 받아 비트 연산을 수행하는 계산기 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	printf("2개의 16진수를 입력 받아 비트 연산 결과 출력\n\n");

	int x, y;	// 두 16진수 저장 변수
	char op;	// 연산자 선택 변수
	int n;	// 입력 성공 개수
	
	while (1) {
		printf("16진수<4자리> 두 개를 입력하시오(종료는 -1 -1) >> ");
		n = scanf("%x %x", &x, &y);	// 16진수 두 변수 저장
		if (x == -1 && y == -1)		// 입력이 -1 -1인 경우 메인 while문 탈출
			break;
		else if (n != 2 || x < 0 || x>0xffff || y < 0 || y > 0xffff) {	// 입력이 잘못된 경우
			while (1) {		// 서브 while문: 입력을 제대로 받을 때까지 반복
				while (getchar() != '\n');		// 입력 버퍼 비우기
				printf(" ?? 다시 입력하시오 : ");
				n = scanf("%x %x", &x, &y);	// 16진수 두 변수 저장
				if (n == 2 && x >= 0 && x < 65536 && y >= 0 && y < 65536) {	// input이 0x0000 0xffff 사이일 때
					break;		// 서브 while문 탈출
				}
			}
		}
		if (n == 2 && x >= 0 && x < 65536 && y >= 0 && y < 65536) {	// input이 0x0000 0xffff 사이일 때
			while (1) {		// 서브 while문: 연산자가 제대로 들어올 때까지 반복
				printf("연산자를 입력하시오[&, |, ^] : ");
				scanf(" %c", &op);
				if (op == '&' || op == '|' || op == '^') {		// 올바른 연산자 일 경우
					switch (op)
					{
					case '&': printf(" >> 연산 결과: %#6x\n\n", x & y); break;
					case '|': printf(" >> 연산 결과: %#6x\n\n", x | y); break;
					case '^': printf(" >> 연산 결과: %#6x\n\n", x ^ y); break;
					default:
						break;
					}
					break;	// 서브 while문 탈출
				}
				else {
					printf(" ?? 연산자를 잘못 선택하셨습니다.\n");
					while (getchar() != '\n');		// 입력 버퍼 비우기
				}
			}
		}
		else if (x == -1 && y == -1)	// 첫번째 서브 while문 입력이 -1 -1 인 경우
			break;		// 메인 while문 탈출
	}
	printf("프로그램을 종료합니다.\n\n");

	return 0;
}