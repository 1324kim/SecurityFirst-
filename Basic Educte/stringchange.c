#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char string[100] = { "" };
	char num1, num2;

	printf("문자열을 입력하세요\n");
	scanf("%s", string);

	printf("변경할 문자 입력\n");
	scanf(" %c", &num1);

	printf("치환할 문자 입력\n");
	scanf(" %c", &num2);

	for (int i = 0; i < 100; i++){
		if (*(string + i) == num1) {
			*(string + i) = num2;
		}
	}

	printf("치환된 문자열은 %s 입니다", string);
	return 0;
}