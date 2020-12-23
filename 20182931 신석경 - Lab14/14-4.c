#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

typedef struct Node {
	char* name;
	struct Node* next;
} Node;

typedef Node* link;

link createNode(char* name);
link appendNode(link head, link node);
void printList(link head);

int main(void) {
	link names = NULL;
	printf("이름의 연결리스트를 만듭니다.\n");
	printf("이름을 입력하고 enter를 누르세요. >> \n");
	char name[32];
	while (gets(name) != NULL) {
		names = appendNode(names, createNode(name));
		printList(names);
	}
	return 0;
}
link createNode(char* name) {
	link node = (link)malloc(sizeof(Node));
	node->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(node->name, name);
	node->next = NULL;

	return node;
}
link appendNode(link head, link node) {
	link nextNode = head;

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
void printList(link head) {
	if (head == NULL) {
		printf("There is no node!!\n");
	}
	else {
		int i = 1;
		while (head != NULL)
		{
			printf("  %d번째 노드는 %s\n", i++, head->name);
			head = head->next;
		}
	}
}