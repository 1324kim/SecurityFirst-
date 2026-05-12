#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char str[100];
	scanf("%s", str);

	FILE* fp;
	fp = fopen("data.txt", "w");
	fputs(str, fp);
	printf("%s", str);
	fclose(fp);
	return 0;
}