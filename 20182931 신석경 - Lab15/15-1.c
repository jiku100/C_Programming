#include <stdio.h>

#define PRINTM(exp) printf("Expression: "#exp" = %d\n", exp);
int main(void) {
	int a = 2;
	PRINTM(3 * 4 + 3 / a);
	return 0;
}