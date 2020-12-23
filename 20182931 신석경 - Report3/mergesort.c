/*******************************************************
* 파일명: mergesort.c
* 프로그램 개요: 리스트를 오름차순으로 각각 정렬하고 정렬된 리스트를 합치는 프로그램
*	배열 출력: printlist() 정의
*	배열 정렬: sort() 정의
*	배열 통합: mergesort() 정의
*
*	입력 1: 복소수를 나타내는 두 개의 실수 입력
*	입력 2: 복소수를 나타내는 두 개의 실수 입력
*
*	출력: 더하기, 빼기, 곱하기, 절댓값의 결과 출력
*
* 날짜: 2020년 11월 04일
* 버전: 1.0
* 작성자: 20182931 신석경
*
*******************************************************/
#include <stdio.h>
#include <stdlib.h>

void printlist(int* list, int cnt);  // 배열 출력
void sort(int* list, int cnt);   // 배열 오름차순으로 정렬
void mergesort(int* clist, int* alist, int* blist, int alen, int blen); // 배열 통합

int main(void) {
    int a[] = { 15, 8, 19, 1, 9, 4, 12, 5 };    // a 배열 선언
    int b[] = { 10, 17, 3, 7, 2 };  // b 배열 선언
    
    int alen = sizeof(a) / sizeof(int); // a 배열 길이 구함
    int blen = sizeof(b) / sizeof(int); // a 배열 길이 구함

    // 두 리스트 출력
    printf("Original list : a[] = "); printlist(a, alen);
    printf("Original list : b[] = "); printlist(b, blen);

    // 두 리스트 정렬
    sort(a, alen);
    sort(b, blen);

    // 두 정렬된 리스트 출력
    printf("\nSorted list : a[] = "); printlist(a, alen);
    printf("Sorted list : b[] = "); printlist(b, blen);

    int* c = calloc(alen + blen, sizeof(int)); // alen + blen 개수 만큼의 배열 선언
    int clen = alen + blen; // clen 설정
    mergesort(c, a, b, alen, blen); // mergesort 실행
    printf("\nMerged list : c[] = "); printlist(c, clen);   // 합병된 리스트 출력
    return 0;
}

void printlist(int* list, int cnt) {  // 배열 출력
    printf("< ");
    for (int i = 0; i < cnt; i++) {
        if (i == cnt - 1) {
            printf("%d >\n", list[i]);
        }
        else {
            printf("%d, ", list[i]);
        }
    }
}

void sort(int* list, int cnt) { // 버블 정렬 구현
    int temp;
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void mergesort(int* clist, int* alist, int* blist, int alen, int blen) { // 배열 통합
    int i = 0, j = 0, k = 0;    // 3개의 배열에 접근하기 위한 인덱스 선언
    while (i < alen && j < blen) {  // alist와 blist에 아직 원소가 남은 경우
        if (alist[i] < blist[j]) {  // alist의 맨 앞 값이 blist의 맨 앞보다 작으면
            clist[k++] = alist[i++];
        }
        else {
            clist[k++] = blist[j++];
        }
    }
    if (i < alen && j >= blen) { // 아직 a에 원소가 남아 있으면
        for (i; i < alen; i++) {
            clist[k++] = alist[i];  // a의 모든 원소 복사
        }
    }
    else if (j < blen && i >= alen) {   // 아직 b에 원소가 남아 있으면
        for (j; j < blen; j++) {
            clist[k++] = blist[j];  // a의 모든 원소 복사
        }
    }
}
