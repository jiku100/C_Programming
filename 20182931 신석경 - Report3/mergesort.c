/*******************************************************
* ���ϸ�: mergesort.c
* ���α׷� ����: ����Ʈ�� ������������ ���� �����ϰ� ���ĵ� ����Ʈ�� ��ġ�� ���α׷�
*	�迭 ���: printlist() ����
*	�迭 ����: sort() ����
*	�迭 ����: mergesort() ����
*
*	�Է� 1: ���Ҽ��� ��Ÿ���� �� ���� �Ǽ� �Է�
*	�Է� 2: ���Ҽ��� ��Ÿ���� �� ���� �Ǽ� �Է�
*
*	���: ���ϱ�, ����, ���ϱ�, ������ ��� ���
*
* ��¥: 2020�� 11�� 04��
* ����: 1.0
* �ۼ���: 20182931 �ż���
*
*******************************************************/
#include <stdio.h>
#include <stdlib.h>

void printlist(int* list, int cnt);  // �迭 ���
void sort(int* list, int cnt);   // �迭 ������������ ����
void mergesort(int* clist, int* alist, int* blist, int alen, int blen); // �迭 ����

int main(void) {
    int a[] = { 15, 8, 19, 1, 9, 4, 12, 5 };    // a �迭 ����
    int b[] = { 10, 17, 3, 7, 2 };  // b �迭 ����
    
    int alen = sizeof(a) / sizeof(int); // a �迭 ���� ����
    int blen = sizeof(b) / sizeof(int); // a �迭 ���� ����

    // �� ����Ʈ ���
    printf("Original list : a[] = "); printlist(a, alen);
    printf("Original list : b[] = "); printlist(b, blen);

    // �� ����Ʈ ����
    sort(a, alen);
    sort(b, blen);

    // �� ���ĵ� ����Ʈ ���
    printf("\nSorted list : a[] = "); printlist(a, alen);
    printf("Sorted list : b[] = "); printlist(b, blen);

    int* c = calloc(alen + blen, sizeof(int)); // alen + blen ���� ��ŭ�� �迭 ����
    int clen = alen + blen; // clen ����
    mergesort(c, a, b, alen, blen); // mergesort ����
    printf("\nMerged list : c[] = "); printlist(c, clen);   // �պ��� ����Ʈ ���
    return 0;
}

void printlist(int* list, int cnt) {  // �迭 ���
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

void sort(int* list, int cnt) { // ���� ���� ����
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

void mergesort(int* clist, int* alist, int* blist, int alen, int blen) { // �迭 ����
    int i = 0, j = 0, k = 0;    // 3���� �迭�� �����ϱ� ���� �ε��� ����
    while (i < alen && j < blen) {  // alist�� blist�� ���� ���Ұ� ���� ���
        if (alist[i] < blist[j]) {  // alist�� �� �� ���� blist�� �� �պ��� ������
            clist[k++] = alist[i++];
        }
        else {
            clist[k++] = blist[j++];
        }
    }
    if (i < alen && j >= blen) { // ���� a�� ���Ұ� ���� ������
        for (i; i < alen; i++) {
            clist[k++] = alist[i];  // a�� ��� ���� ����
        }
    }
    else if (j < blen && i >= alen) {   // ���� b�� ���Ұ� ���� ������
        for (j; j < blen; j++) {
            clist[k++] = blist[j];  // a�� ��� ���� ����
        }
    }
}
