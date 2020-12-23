#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592
#define AREA(r) (PI * r * r)
typedef struct{
	float x;
	float y;
} point;


typedef struct {
	point point;
	float radius;
} circle;


int main(void) {
	circle* c = malloc(sizeof(circle));

	int n;

	printf("���� �߽� ��ǥ<x,y>, �������� ���ʷ� �Է��Ͻÿ�\n");
	printf("<��: 2.89 4.25 3.48> => ");
	while ((n = scanf("%f %f %f", &c->point.x, &c->point.y, &c->radius)) != 3) {
		printf("?? �Է��� �߸��Ǿ����ϴ�. �ٽ� �Է��Ͻÿ�\n");
		printf("<��: 2.89 4.25 3.48> => ");
		while (getchar() != '\n');
	}
	printf("\n");
	printf("�� �߽���ǥ<%.2f, %.2f>\n", c->point.x, c->point.y);
	printf("�� ������: %.2f\n", c->radius);
	printf("�� ����: %.2f\n", AREA(c->radius));

	return 0;
}
