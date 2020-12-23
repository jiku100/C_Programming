#include <stdio.h>


//********************* 9-6 1번
// Expect: 200 330 330

//int n = 100;
//int main(void)
//{
//	int n = 200;
//	printf("%d ", n);
//
//	for (n = 0; n < 2; n++) {
//		int n = 300;
//		n += 30;
//		printf("%d ", n);
//	}
//	printf("\n");
//
//	return 0;
//}

//********************* 9-6 2번
// Expect: 100 400 900

//int save(int);
//
//int main(void)
//{
//	printf("%d ", save(100));
//	printf("%d ", save(300));
//	printf("%d\n", save(500));
//
//	return 0;
//}
//
//int save(int money)
//{
//	static int amount;
//	return amount += money;
//}

//********************* 9-6 3번
// Expect: 11 13 8

//int g = 1;
//int sub(void);
//
//int main(void)
//{
//	int b = 5;
//
//	printf("%d ", sub());
//	printf("%d ", sub());
//	printf("%d\n", g + b);
//
//	return 0;
//}
//
//int sub(void)
//{
//	static int s = 10;
//
//	return s++ + g++;
//}

//********************* 9-6 4번
// Expect: 6 4
//		   7 3
//         8 2
//         9 1
//         10 0

void func(void);
static count = 5;

int main(void)
{
	while (count--)
		func();

	return 0;
}

void func(void)
{
	static i = 5;

	printf("%d %d\n", ++i, count);
}
