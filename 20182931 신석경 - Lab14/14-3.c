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
	if ((in = fopen("in.txt", "r")) == NULL) {	// in.txt �� �б� �������� ����
		printf("in.txt ������ ���� �� �����ϴ�.\n");
		exit(1);
	}

	student* students = NULL;
	char line[80];	// �� ���� �о�� ����
	int order;
	float score1, score2, sum;
	char name[32];
	fgets(line, 80, in);	// in���� �� ���� �о��

	while (!feof(in)) {
		// �Ʒ��� ���Ĵ�� in.txt���� ����ü ������ �и���
		sscanf(line, "%d    %s    %f    %f", &order, name, &score1, &score2);
		students = append(students, createNode(order, name, score1, score2));
		fgets(line, 80, in);	// in���� �� ���� �о��
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
		printf("%5s%8s%10s%8s%10s\n", "��ȣ", "�̸�", "����1", "����2", "�հ�");
		printf("============================================\n");
		while(head != NULL)
		{
			printf("%3d%12s%8.1f%8.1f%10.1f\n", head->order, head->name, head->score1, head->score2, head->sum);
			head = head->next;
		}
		printf("--------------------------------------------\n");
	}
}