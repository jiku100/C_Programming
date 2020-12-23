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

	printf("원의 중심 좌표<x,y>, 반지름을 차례로 입력하시오\n");
	printf("<예: 2.89 4.25 3.48> => ");
	while ((n = scanf("%f %f %f", &c->point.x, &c->point.y, &c->radius)) != 3) {
		printf("?? 입력이 잘못되었습니다. 다시 입력하시오\n");
		printf("<예: 2.89 4.25 3.48> => ");
		while (getchar() != '\n');
	}
	printf("\n");
	printf("원 중심좌표<%.2f, %.2f>\n", c->point.x, c->point.y);
	printf("원 반지름: %.2f\n", c->radius);
	printf("원 면적: %.2f\n", AREA(c->radius));

	return 0;
}
