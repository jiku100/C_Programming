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
	printf("이름의 연결리스트를 만듭니다.\n");
	printf("이름을 입력하고 enter를 누르세요.\n >> ");
	char name[32];
	while (gets(name) != NULL) {	// 이름 가져온다. ctrl-z 이면 gets()가 NULL을 반환하기 때문에 종료
		names = appendNode(names, createNode(name));	// 노드를 만들고 연결 리스트에 추가
		recprintList(names, 1);	// 재귀적으로 이름 출력, 기본적으로 1번부터 출력하여 i에 1 할당
		printf(">> ");
	}
	return 0;
}
link createNode(char* name) {	// 노드 생성 함수
	link node = (link)malloc(sizeof(Node));	// 동적 할당
	node->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(node->name, name);	// 이름 할당
	node->next = NULL;	// 다음 링크 NULL로 설정

	return node;	// 생성한 노드 반환
}
link appendNode(link head, link node) {	// 노드 추가 함수
	link nextNode = head;

	if (head == NULL) {	// head == NULL -> 처음에 추가
		head = node;
		return head;
	}

	while (nextNode->next != NULL) {	// 아닌 경우 마지막을 찾아서
		nextNode = nextNode->next;
	}

	nextNode->next = node;	// 마지막에 노드 추가

	return head;
}
void recprintList(link head, int i) {	// 재귀적으로 연결 리스트를 출력하는 함수
	if (head == NULL) {	// 넘어온 head 가 NULL 이면 함수 종료
		return;
	}
	else {	// 넘어온 head 가 NULL이 아니면
		printf("  %d번째 노드는 %s\n", i, head->name);	// 해당 순번과 해당 노드의 이름 출력
		head = head->next;	// head를 next로 이동시켜주고
		recprintList(head, ++i);	// 이동시킨 head와 1을 증가시킨 i를 가지고 다시 함수를 호출하여 재귀적으로 연결리스트 출력
	}
	return;
}