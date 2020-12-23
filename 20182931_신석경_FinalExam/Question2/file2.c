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

	if ((in = fopen(argv[1], "r")) == NULL) {	// argv[1] 를 읽기 전용으로 열음
		printf("%s 파일을 읽을 수 없습니다.\n", argv[1]);
		exit(1);
	}

	char line[80];	// 한 줄을 읽어올 변수
	int order;
	char name[32];
	float score1;
	float score2;	// 여기까지 정보를 저장할 변수
	link students = NULL;	// 처음에는 head를 NULL로 설정
	fgets(line, 80, in);	// in에서 한 줄을 읽어옴
	while (!feof(in)) {
		// 아래의 형식대로 in.txt에서 구조체 정보를 분리함
		sscanf(line, "%d    %s    %f    %f", &order, name, &score1, &score2);	// 읽어온 한 줄을 형식에 맞춰서 각각의 변수에 저장
		students = appendNode(students, createNode(order, name, score1, score2));	// 노드를 만들고 그것을 head에 저장
		fgets(line, 80, in);	// in에서 한 줄을 읽어옴
	}
	printf("--------------------------------------------\n");
	printf("%5s%8s%10s%8s%10s\n", "번호", "이름", "과목1", "과목2", "합계");
	printf("============================================\n");
	printList(students);	// 연결리스트 출력
	printf("--------------------------------------------\n");
	return 0;
}

link createNode(int order, char* name, float score1, float score2) {		// 입력된 정보로 노드 만들어 반환
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

link appendNode(link head, link node) {	// 노드를 head에 추가
	link nextNode = head;

	if (head == NULL) {		// 비엇으면 처음에
		head = node;
		return head;
	}

	while (nextNode->next != NULL) {	// 아니면 마지막까지 검사해서
		nextNode = nextNode->next;
	}

	nextNode->next = node;	// 마지막에 추가

	return head;
}

void printList(link head) {	// 연결리스트를 출력 
	if (head == NULL) {	// 연결 리스트가 비었으면 
		printf("There is no node!!\n");
	}
	else {
		int i = 1;
		while (head != NULL)	// head가 NULL이 아닐 때까지
		{
			//정보 출력
			printf("%3d%12s%8.1f%8.1f%10.1f\n", head->order, head->name, head->score1, head->score2, head->sum);
			head = head->next;	// 다음 노드로 이동
		}
	}
}