#include <stdio.h>

int cardinput() {
	int num;
	printf("입력받을 카드 수를 입력하세요\n");
	scanf_s("%d", &num);
	
	return num;
}

int cardsum(int num) {
	int sum = 0, card;

	for (int i = 0; i < num - 1; i++) {
		scanf_s("%d", &card);

		if (card > num || card < 1) {
			printf("잘못된 입력입니다");
			exit(1);
		}

		sum += card;
	}
	return sum;
}



int main(){
	int n = cardinput();
	int inputsum = cardsum(n);
	int total = n * (n + 1) / 2;
	printf("빠진 카드는 %d 입니다", total - inputsum);
	return 0;
}