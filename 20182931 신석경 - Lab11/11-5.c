/*
* My opinion
*   1. #include <stdarg.h> 필요
*		가변 인자를 사용하기 위해서는 위의 헤더파일이 필요하다.
* 
*	2. va_start(argp) -> va_start(argp, numagers)
*		va_start 에는 가변 인자로 받을 변수 이외에 
*       가변 인자를 시작하기 전 마지막 고정 인자의 이름을 전달해야한다.
* 
*   3. va_arg(argp) -> va_arg(argp, double)
*		va_arg에는 가변 인자를 어떤 타입으로 받아올 것인지 선언해주어야 한다.
* 
*   4. sum(5, ....) -> sum(6, ....)
*       가변 인자로 넘어간 숫자의 개수는 6개인데, sum에서 5개만을 더한다.
*/


#include <stdio.h>
#include <stdarg.h>
double sum(int count, ...); //int count 이후는 가변인자 ...

int main(void)
{
	printf("합 %.1f\n", sum(6, 1.2, 2.1, 3.8, 4.3, 5.9, 8.6));

	return 0;
}
double sum(int numagrs, ...)
{
	va_list argp; //가변인자 변수 선언

	//numargs 이후의 가변인자 처리 시작 
	va_start(argp, numagrs);

	double total = 0; //합이 저장될 변수
	for (int i = 0; i < numagrs; i++)
		//지정하는 double 형으로 가변인자 하나 하나를 반환
		total += va_arg(argp, double);

	va_end(argp); //가변인자 처리 종료

	return total;
}
