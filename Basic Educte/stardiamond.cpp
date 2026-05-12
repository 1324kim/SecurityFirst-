#include <stdio.h>
int main() {
	int num, under;
	int count = 1;
	char space = ' ';

	printf("[>] 크기를 입력해주세요\n[>] ");
	scanf_s("%d", &num);
	printf("\n[>] 결과를 출력합니다\n");

	while (num != 0) { //상단 별 출력
		for (int i = 1; i <= num; i++) {
			if (i < num) printf("%c", space); //공백출력
			else if (i == num) { //별출력
				for (int j = 1; j <= count; j++) {
					printf("*");
				}
				printf("\n");
				num--;
				count += 2;
			}
		}
	}

	under = count - 4; //처음으로 출력되는 하단 별 개수 설정
	count = 1; //카운트 값 초기화

	while (under >= 1) { //하단 별 출력
		for (int i = 1; i <= count; i++) {
			printf("%c", space); //공백출력
			if (i == count) { //별출력
				for (int j = 1; j <= under; j++) {
					printf("*");
				}
				printf("\n");
			}
		}
		count++;
		under = under - 2;
	}

	return 0;
}