#include <stdio.h>
int main() {
	int num;

	printf("[>] 몇 단까지 출력하고 싶은지 입력해주세요\n[<] ");	
	scanf_s("%d", &num);
	printf("\n%d단 까지 출력\n", num);

	for (int i = 1; i <= 9; i++){
		for (int j = 2; j <= num; j++){
			printf("%d * %d = %2d\t", j, i, (j * i));
		}
		printf("\n");
	}
	return 0;
}