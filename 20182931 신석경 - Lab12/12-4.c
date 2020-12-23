#include <stdio.h>
#include <stdarg.h>

double vasum(char*, ...);

int main(void) {
    double result = vasum("dfdf", 3, 20.75, 51, 21.91);
    printf("정수와 실수의 모든 데이터의 합 : %.2f\n", result);
    return 0;
}

double vasum(char* types, ...) {
	va_list argp;

	va_start(argp, types);

	int i = 0;
    double total = 0;
    double temp;

    printf("정수와 실수 데이터 : ");
    while (types[i] != '\0')    
    {
        switch (types[i])      
        {
        case 'd':  
            temp = va_arg(argp, int);
            printf("%3.0f ", temp);
            total += temp;
            break;
        case 'f':  
            temp = va_arg(argp, double);
            printf("%6.2f ", temp);   
            total += temp;
            break;
        default:
            break;
        }
        i++;
    }
    printf("\n");
    va_end(argp);
    return total;
}

