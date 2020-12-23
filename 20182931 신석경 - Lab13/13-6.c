#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	FILE* f;

	if ((f = fopen("imput2.txt", "r")) == NULL) {
		fprintf(stdout, "파일 읽기 실패!!\n");
		exit(1);
	}

	fprintf(stdout, "\n\n%9sAnalysis Result of imput2.txt\n", "");
	fprintf(stdout, "------------------------------------------\n");
	int characters = 0;
	int words = 0;
	int lines = 0;
	char line[1024];
	char* ptr = NULL;
	int len;
	fgets(line, 1024, f);
	lines++;
	while (!feof(f)) {
		ptr = strtok(line, "()!?,.\t\n ");
		while (ptr != NULL)
		{
			if (strcmp(ptr, "\n") == 0)
				break;
			if (isalpha(ptr[0])) {
				len = strlen(ptr);
				characters += len;
				
			}
			words++;
			ptr = strtok(NULL, "()!?,.\t\n ");
		}
		fgets(line, 1024, f);
		lines++;
	}
	printf("%30s : %6d\n", "Number of Characters", characters);
	printf("%30s : %6d\n", "Number of Words", words);
	printf("%30s : %6d\n", "Number of Lines", lines - 1);
	fclose(f);
	return 0;
}