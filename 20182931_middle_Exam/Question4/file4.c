#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int mystrlen(char* str);
int mystrcmp(char* str1, char* str2);
int mystrncmp(char* str2, char* str3, int n);
void mystrcpy(char* dest, char* str1);

int main(void) {
	char* str1 = "C Language";
	char* str2 = "C language";
	char* str3 = "C languages";
	char dst[64] = " ";
	printf("str1 = %s\n", str1);
	printf("str2 = %s\n", str2);
	printf("str3 = %s\n", str3);
	printf("dest = %s\n\n", dst);

	printf("strlen<str1> = %d\n", strlen(str1));
	printf("mystrlen<str1> = %d\n\n", mystrlen(str1));

	printf("strcmp<str1> = %d\n", strcmp(str1, str2));
	printf("mystrcmp<str1> = %d\n\n", mystrcmp(str1, str2));

	printf("strncmp<str2, str3, 10> = %d\n", strncmp(str2, str3, 10));
	printf("mystrncmp<str2, str3, 10> = %d\n\n", mystrncmp(str2, str3, 10));

	strcpy(dst, str1);
	printf("strcpy<dest, str1> = %s\n", dst);
	mystrcpy(dst, str1);
	printf("mystrcpy<dest, str1> = %s\n\n", dst);
	return 0;
}


int mystrlen(char* str) {
	int n;
	for (n = 0; str[n]; n++);	// str[n]이 '\n' 혹은 NULL이 나올 때 까지	n값을 증가시킴
	return n;
}

int mystrcmp(char* str1, char* str2) {
	int result;
	while (*str1 && *str2) {	// str1과 str2가 NULL이 아닐 때 까지
		if (*str1 != *str2) {	// 두 문자가 다르면
			break;
		}
		str1++;	// 다음 문자 비교
		str2++;	// 다음 문자 비교
	}
	result = *str1 - *str2; // 검사한 문자에서의 차
	if (result < 0)	// 음수면 -1
		result = -1;
	else if (result > 0)	// 양수면 1
		result = 1;
	
	return result;
}

int mystrncmp(char* str2, char* str3, int n) {
	int result;
	int i = 0;
	for (i; i < n; i++) {
		if (!str2[i] || !str3[i])	// 둘 중에 아무거나 NULL이라면
			break;
		else if (str2[i] != str2[i])	// 둘의 문자가 다르면
			break;

	}
	int n1 = strlen(str2);	// 두 문자열 길이 구함
	int n2 = strlen(str3);
	// for 문이 끝까지 돌고 그 때의 i가 문자열 길이와 같으면 i 값은 검사하려고한 문자 다음 index를 가리킨다. 그러므로 1을 뺀다.
	if (n1 == i) {
		i--;
	}
	else if (n2 == i) {
		i--;
	}
	result = str2[i] - str3[i]; // 검사한 문자에서의 차, 이때 i는 for문에서 증가하고 끝나기 때문에
	// 검사한 문자 다음 index를 가리키므로 1을 빼줘야한다.
	if (result < 0)	// 음수면 -1
		result = -1;
	else if (result > 0)	// 양수면 1
		result = 1;

	return result;
}

void mystrcpy(char* dest, char* str1) {
	int index = 0;
	while (str1[index]) {
		dest[index] = str1[index];
		index++;
	}
	dest[index] = str1[index];	// NULL 문자까지 복사
}