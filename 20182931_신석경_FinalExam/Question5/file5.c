#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectionSort(char* str[], int arysize);
void printAry(char* str[], int arysize);

int main(void) {
	char* str[] = { "pascal","java","Ada","Python","C#","C++","C","Ruby","basic","Lisp" };
	int arysize = sizeof(str) / sizeof(char*);
	printf("선택 정렬<Selection Sorting> ....\n");
	printf("정렬 전 순서\n");
	printAry(str, arysize);
	selectionSort(str, arysize);
	printf("\n정렬 후 순서\n");
	printAry(str, arysize);
	return 0;
}

void selectionSort(char* str[], int arysize) {	//선택 정렬 기반 문자열 정렬 함수
	for (int i = 0; i < arysize - 1; i++) {	// 마지막 전 원소까지 검사
		int min = i;	// 최소를 i라 가정
		for (int j = i + 1; j < arysize; j++) {	// i+1 부터 마지막 원소까지 검사
			if(strcmp(str[j], str[min]) < 0) {	// strcmp(a, b)의 결과가 음수라는 것은 사전적으로 a가 b의 앞에 있다는 것
				min = j;	// 따라서 j가 min이 됨
			}
		}
		// 여기까지 최소가 되는 원소 찾음 따라서 i와 min을 바꾸는 것으로 정렬가능
		char* temp = str[i];	// 이제 i와 min의 char*를 바꿔서 문자열을 정렬한다.
		str[i] = str[min];
		str[min] = temp;
	}
}

void printAry(char* str[], int arysize) {	// 문자열 배열을 출력하는 함수
	for (int i = 0; i < arysize; i++) {
		printf("%s ", str[i]);
	}
	printf("\n");
}