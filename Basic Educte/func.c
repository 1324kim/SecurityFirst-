#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void inpu(int *a, int *b, char arr[]) {
	scanf("%d %d %s", a, b, arr);
}

int outpu(int *a, int *b, char arr[]) {
	return printf("숫자1 : %d\n숫자2 : %d\n문자열 : %s\n", *a, *b, arr);
}

int main() {
	int num1 = 0, num2 = 0;

	char arr[20] = {'\0'};

	inpu(&num1, &num2, arr);

	outpu(&num1, &num2, arr);

	return 0;
}