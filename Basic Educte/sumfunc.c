#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum1 = 0;
int sum2 = 0;

void sum10(int num) {
	if (num >= 0) {
		sum1 += num;
		sum10(num - 1);
	}
	if (num == 0) {
		printf("1부터 10까지의 합 : %d\n", sum1);
		return;
	}
}

void sum50(int num) {
	if (num >= 0) {
		sum2 += num;
		sum50(num - 1);
	}
	if (num == 0) {
		printf("1부터50까지의 합 : %d\n", sum2);
		return;
	}
}

int main() {
	sum10(10);
	sum50(50);
	return 0;
}