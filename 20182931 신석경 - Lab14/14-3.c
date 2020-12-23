#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>


typedef struct student {
	int order;
	char* name;
	float score1;
	float score2;
	float sum;
	struct student* next;
} student;

student* createNode(int order, char* name, float score1, float score2);
student* append(student* head, student* node);
void printList(student* head);

int main(void) {
	FILE* in;
	if ((in = fopen("in.txt", "r")) == NULL) {	// in.txt 를 읽기 전용으로 열음
		printf("in.txt 파일을 읽을 수 없습니다.\n");
		exit(1);
	}

	student* students = NULL;
	char line[80];	// 한 줄을 읽어올 변수
	int order;
	float score1, score2, sum;
	char name[32];
	fgets(line, 80, in);	// in에서 한 줄을 읽어옴

	while (!feof(in)) {
		// 아래의 형식대로 in.txt에서 구조체 정보를 분리함
		sscanf(line, "%d    %s    %f    %f", &order, name, &score1, &score2);
		students = append(students, createNode(order, name, score1, score2));
		fgets(line, 80, in);	// in에서 한 줄을 읽어옴
	}

	printList(students);
	return 0;
}

student* createNode(int order, char* name, float score1, float score2) {
	student* node = (student*)malloc(sizeof(student));
	node->order = order;
	node->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(node->name, name);
	node->score1 = score1;
	node->score2 = score2;
	node->sum = score1 + score2;
	node->next = NULL;

	return node;
}

student* append(student* head, student* node) {
	student* nextNode = head;

	if (head == NULL) {
		head = node;
		return head;
	}

	while (nextNode->next != NULL) {
		nextNode = nextNode->next;
	}

	nextNode->next = node;

	return head;
}

void printList(student* head) {
	if (head == NULL) {
		printf("There is no node!!\n");
	}
	else {
		printf("--------------------------------------------\n");
		printf("%5s%8s%10s%8s%10s\n", "번호", "이름", "과목1", "과목2", "합계");
		printf("============================================\n");
		while(head != NULL)
		{
			printf("%3d%12s%8.1f%8.1f%10.1f\n", head->order, head->name, head->score1, head->score2, head->sum);
			head = head->next;
		}
		printf("--------------------------------------------\n");
	}
}