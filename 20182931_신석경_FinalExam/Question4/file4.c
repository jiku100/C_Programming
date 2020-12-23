#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char* name;
	struct Node* next;
} Node;

typedef Node* link;

link createNode(char* name);
link appendNode(link head, link node);
void recprintList(link head, int i);

int main(void) {
	link names = NULL;
	printf("�̸��� ���Ḯ��Ʈ�� ����ϴ�.\n");
	printf("�̸��� �Է��ϰ� enter�� ��������.\n >> ");
	char name[32];
	while (gets(name) != NULL) {	// �̸� �����´�. ctrl-z �̸� gets()�� NULL�� ��ȯ�ϱ� ������ ����
		names = appendNode(names, createNode(name));	// ��带 ����� ���� ����Ʈ�� �߰�
		recprintList(names, 1);	// ��������� �̸� ���, �⺻������ 1������ ����Ͽ� i�� 1 �Ҵ�
		printf(">> ");
	}
	return 0;
}
link createNode(char* name) {	// ��� ���� �Լ�
	link node = (link)malloc(sizeof(Node));	// ���� �Ҵ�
	node->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(node->name, name);	// �̸� �Ҵ�
	node->next = NULL;	// ���� ��ũ NULL�� ����

	return node;	// ������ ��� ��ȯ
}
link appendNode(link head, link node) {	// ��� �߰� �Լ�
	link nextNode = head;

	if (head == NULL) {	// head == NULL -> ó���� �߰�
		head = node;
		return head;
	}

	while (nextNode->next != NULL) {	// �ƴ� ��� �������� ã�Ƽ�
		nextNode = nextNode->next;
	}

	nextNode->next = node;	// �������� ��� �߰�

	return head;
}
void recprintList(link head, int i) {	// ��������� ���� ����Ʈ�� ����ϴ� �Լ�
	if (head == NULL) {	// �Ѿ�� head �� NULL �̸� �Լ� ����
		return;
	}
	else {	// �Ѿ�� head �� NULL�� �ƴϸ�
		printf("  %d��° ���� %s\n", i, head->name);	// �ش� ������ �ش� ����� �̸� ���
		head = head->next;	// head�� next�� �̵������ְ�
		recprintList(head, ++i);	// �̵���Ų head�� 1�� ������Ų i�� ������ �ٽ� �Լ��� ȣ���Ͽ� ��������� ���Ḯ��Ʈ ���
	}
	return;
}