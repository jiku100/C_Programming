/*
* My opinion
*   1. #include <stdarg.h> �ʿ�
*		���� ���ڸ� ����ϱ� ���ؼ��� ���� ��������� �ʿ��ϴ�.
* 
*	2. va_start(argp) -> va_start(argp, numagers)
*		va_start ���� ���� ���ڷ� ���� ���� �̿ܿ� 
*       ���� ���ڸ� �����ϱ� �� ������ ���� ������ �̸��� �����ؾ��Ѵ�.
* 
*   3. va_arg(argp) -> va_arg(argp, double)
*		va_arg���� ���� ���ڸ� � Ÿ������ �޾ƿ� ������ �������־�� �Ѵ�.
* 
*   4. sum(5, ....) -> sum(6, ....)
*       ���� ���ڷ� �Ѿ ������ ������ 6���ε�, sum���� 5������ ���Ѵ�.
*/


#include <stdio.h>
#include <stdarg.h>
double sum(int count, ...); //int count ���Ĵ� �������� ...

int main(void)
{
	printf("�� %.1f\n", sum(6, 1.2, 2.1, 3.8, 4.3, 5.9, 8.6));

	return 0;
}
double sum(int numagrs, ...)
{
	va_list argp; //�������� ���� ����

	//numargs ������ �������� ó�� ���� 
	va_start(argp, numagrs);

	double total = 0; //���� ����� ����
	for (int i = 0; i < numagrs; i++)
		//�����ϴ� double ������ �������� �ϳ� �ϳ��� ��ȯ
		total += va_arg(argp, double);

	va_end(argp); //�������� ó�� ����

	return total;
}
