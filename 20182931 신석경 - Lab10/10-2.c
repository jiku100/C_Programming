#include <stdio.h>

struct person {
	char name[20];
	char phonenumber[14];
	char address[64];
};


int main(void) {
	struct person p1 = { "홍길동", "011-1111-1111", "서울시 구로구 고척동" };
	struct person p2 = { "이순신", "017-3245-3278", "서울시 강남구 도곡동" };
	struct person p3 = { "박문수", "011-2222-2456", "경기도 안양시 비산동" };

	printf("--------------------------------------------------\n");
	printf("    이 름       전화번호                 주 소\n");
	printf("--------------------------------------------------\n");
	printf("  %s    %s\t%s\n", p1.name, p1.phonenumber, p1.address);
	printf("  %s    %s\t%s\n", p2.name, p2.phonenumber, p2.address);
	printf("  %s    %s\t%s\n", p3.name, p3.phonenumber, p3.address);
	printf("--------------------------------------------------\n");
	return 0;
}