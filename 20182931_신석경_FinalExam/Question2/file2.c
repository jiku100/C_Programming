#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student {
	int order;
	char* name;
	float score1;
	float score2;
	float sum;
	struct Student* next;
} Student;

typedef Student* link;

link createNode(int order, char* name, float score1, float score2);
link appendNode(link head, link node);
void printList(link head);

int main(int argc, char* argv[])
{
	if (argc < 2) {
		printf("Error\n");
		exit(0);
	}
	
	FILE* in;

	if ((in = fopen(argv[1], "r")) == NULL) {	// argv[1] �� �б� �������� ����
		printf("%s ������ ���� �� �����ϴ�.\n", argv[1]);
		exit(1);
	}

	char line[80];	// �� ���� �о�� ����
	int order;
	char name[32];
	float score1;
	float score2;	// ������� ������ ������ ����
	link students = NULL;	// ó������ head�� NULL�� ����
	fgets(line, 80, in);	// in���� �� ���� �о��
	while (!feof(in)) {
		// �Ʒ��� ���Ĵ�� in.txt���� ����ü ������ �и���
		sscanf(line, "%d    %s    %f    %f", &order, name, &score1, &score2);	// �о�� �� ���� ���Ŀ� ���缭 ������ ������ ����
		students = appendNode(students, createNode(order, name, score1, score2));	// ��带 ����� �װ��� head�� ����
		fgets(line, 80, in);	// in���� �� ���� �о��
	}
	printf("--------------------------------------------\n");
	printf("%5s%8s%10s%8s%10s\n", "��ȣ", "�̸�", "����1", "����2", "�հ�");
	printf("============================================\n");
	printList(students);	// ���Ḯ��Ʈ ���
	printf("--------------------------------------------\n");
	return 0;
}

link createNode(int order, char* name, float score1, float score2) {		// �Էµ� ������ ��� ����� ��ȯ
	link node = (link)malloc(sizeof(Student));
	node->order = order;
	node->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(node->name, name);
	node->score1 = score1;
	node->score2 = score2;
	node->sum = score1 + score2;
	node->next = NULL;
	return node;
}

link appendNode(link head, link node) {	// ��带 head�� �߰�
	link nextNode = head;

	if (head == NULL) {		// ������� ó����
		head = node;
		return head;
	}

	while (nextNode->next != NULL) {	// �ƴϸ� ���������� �˻��ؼ�
		nextNode = nextNode->next;
	}

	nextNode->next = node;	// �������� �߰�

	return head;
}

void printList(link head) {	// ���Ḯ��Ʈ�� ��� 
	if (head == NULL) {	// ���� ����Ʈ�� ������� 
		printf("There is no node!!\n");
	}
	else {
		int i = 1;
		while (head != NULL)	// head�� NULL�� �ƴ� ������
		{
			//���� ���
			printf("%3d%12s%8.1f%8.1f%10.1f\n", head->order, head->name, head->score1, head->score2, head->sum);
			head = head->next;	// ���� ���� �̵�
		}
	}
}