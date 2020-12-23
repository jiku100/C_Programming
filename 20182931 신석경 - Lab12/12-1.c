/****************/
// 1-1 ����
/*
* 1. myprint() -> myprint
*	�Լ� �����Ϳ� �Ҵ��� ������ �Լ��� �ּҰ��� �˸� �Ǵ� 
*	�Լ� �ּҰ��� ��Ÿ���� �Լ��� �̸��� ��� �Ѵ�.
*/

//#include <stdio.h>
//void myprint(int x);
//
//int main()
//{
//	void (*p)(int);
//	p = myprint;
//
//	p(2);
//	(*p)(4);
//
//	return 0;
//}
//
//void myprint(int x)
//{
//	printf("%d\n", x);
//}

/****************/
// 1-2 ����
/*
* 1. *pa(0) -> *pa[0], *pa(1) -> *pa[1]
*	�Լ� ������ �迭�� �迭�̱� ������ �ش� index�� ���ҿ� �����ϱ� ���ؼ���
*	���ȣ�� ����Ͽ� �����ؾ� �Ѵ�.
*/

//#include <stdio.h>
//
//int subtract(int, int);
//int add(int, int);
//
//int main(void)
//{
//	int(*pa[])(int, int) = { add, subtract };
//
//	printf("��: %d\n", (*pa[0])(10, 2));
//	printf("��: %d\n", (*pa[1])(10, 2));
//
//	return 0;
//}
//
//int subtract(int x, int y) {
//	return x - y;
//}
//int add(int x, int y) {
//	return x + y;
//}

/****************/
// 1-3 ����
/*
* 1. (int*)ptr -> *(int*)ptr, (double*)ptr -> *(double*)ptr
*	void �����͸� ����ȯ�� �ؼ��� ���� ������ �ʴ´�. �տ� ���� ������
*	�ؼ� ���� ��µǵ��� �Ѵ�.
*/
#include <stdio.h>

int main(void)
{
	int a = 100;
	double b = 32.83;

	void* ptr = &a;
	printf("%d ", *(int*)ptr); //�� ���
	ptr = &b;
	printf("%.2f\n", *(double*)ptr); //�� ���

	return 0;
}
