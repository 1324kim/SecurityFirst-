#include <stdio.h>
int main() {
	int num, count = 0;
	scanf_s("%d", &num);
	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {
			count++;
			printf("%d번쨰 약수 : %d\n", count, i);
		}
	}
	printf("총약수의 개수는 %d 개", count);
	return 0;
}