#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

typedef struct Node {
	int num;
	struct Node* next;
} Node;

typedef Node* link;

link createNode(int data);
link appendNode(link head, link node);
link insertNode(link head, link node);
link deleteNode(link head, link node);
link createList(int* data, int num);
void printList(link head);

int main(void) {
	link nodes = NULL;
	int data[] = { 10, 20, 40, 70, 90 };
	int target;
	nodes = createList(data, sizeof(data) / sizeof(int));
	printf("Original List\n");
	printList(nodes);
	printf("삽입할 노드의 숫자를 입력하시오 => ");	scanf("%d", &target);
	
	nodes = insertNode(nodes, createNode(target));
	printf("Updated List after insert %d\n", target);
	printList(nodes);

	printf("제거할 노드의 숫자를 입력하시오 => ");	scanf("%d", &target);
	nodes = deleteNode(nodes, createNode(target));
	printf("Updated List after delete %d\n", target);
	printList(nodes);
	return 0;
}

link createNode(int data) {
	link node = (link)malloc(sizeof(Node));
	node->num = data;
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

link insertNode(link head, link node) {
	link curNode = head;

	if (head == NULL) {
		head = node;
		return head;
	}
	if (node->num < head->num) {
		node->next = head;
		head = node;
	}
	else {
		while (curNode != NULL) {
			if (curNode->next == NULL) {
				curNode->next = node;
				break;
			}
			else if (node->num >= curNode->num && node->num < curNode->next->num) {
				link temp = curNode->next;
				curNode->next = node;
				node->next = temp;
				break;
			}
			else
				curNode = curNode->next;
		}
	}

	return head;
}

link deleteNode(link head, link node) {
	link curNode = head;
	if (node->num == head->num) {
		link temp = curNode;
		head = head->next;
		free(temp);
	}
	else {
		while (curNode->next != NULL) {
			if (node->num == curNode->next->num) {
				link temp = curNode->next;
				curNode->next = temp->next;
				free(temp);
				break;
			}
			else
				curNode = curNode->next;
		}
	}
	return head;
}

link createList(int* data, int num) {
	link head = NULL;
	for (int i = 0; i < num; i++) {
		head = appendNode(head, createNode(data[i]));
	}
	return head;
}

void printList(link head) {
	if (head == NULL) {
		printf("There is no node!!\n");
	}
	else {
		while (head != NULL)
		{
			printf("%d -> ", head->num);
			head = head->next;
		}
		printf("NULL\n");
	}
	printf("\n");
}