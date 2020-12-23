/****************/
// 1-1 문제
/*
* 1. myprint() -> myprint
*	함수 포인터에 할당할 때에는 함수의 주소값만 알면 되니 
*	함수 주소값을 나타내는 함수의 이름만 써야 한다.
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
// 1-2 문제
/*
* 1. *pa(0) -> *pa[0], *pa(1) -> *pa[1]
*	함수 포인터 배열도 배열이기 때문에 해당 index의 원소에 접근하기 위해서는
*	대괄호를 사용하여 접근해야 한다.
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
//	printf("합: %d\n", (*pa[0])(10, 2));
//	printf("차: %d\n", (*pa[1])(10, 2));
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
// 1-3 문제
/*
* 1. (int*)ptr -> *(int*)ptr, (double*)ptr -> *(double*)ptr
*	void 포인터를 형변환만 해서는 값이 나오지 않는다. 앞에 간접 참조를
*	해서 값이 출력되도록 한다.
*/
#include <stdio.h>

int main(void)
{
	int a = 100;
	double b = 32.83;

	void* ptr = &a;
	printf("%d ", *(int*)ptr); //값 출력
	ptr = &b;
	printf("%.2f\n", *(double*)ptr); //값 출력

	return 0;
}
