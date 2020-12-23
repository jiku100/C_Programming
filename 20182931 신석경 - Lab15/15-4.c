#include <stdio.h>

void bubbleSort(int* ary, int arysize);	
void printAry(int* ary, int arysize);

int main(void) {
	int ary[] = { 6, 3, 11, 9, 12, 2, 8, 15, 18, 10, 7, 14 };
	int arysize = sizeof(ary) / sizeof(ary[0]);
	printf("선택 정렬<Bubble Sorting> ....\n");
	printf("정렬 전 순서\n");
	printAry(ary, arysize);
	bubbleSort(ary, arysize);
	printf("\n정렬 후 순서\n");
	printAry(ary, arysize);
	return 0;
}

void bubbleSort(int* ary, int arysize) {
	for (int i = 0; i < arysize; i++) {
		for (int j = 1; j < arysize - i; j++) {
			if (ary[j - 1] > ary[j]) {
				int temp = ary[j - 1];
				ary[j - 1] = ary[j];
				ary[j] = temp;
			}
		}
	}
}

void printAry(int* ary, int arysize) {
	for (int i = 0; i < arysize; i++) {
		printf("%4d", ary[i]);
	}
	printf("\n");
}