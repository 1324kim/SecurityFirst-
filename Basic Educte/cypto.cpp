#include <stdio.h>
int main() {
	int sel, en, en1, en2, en3, en4, de, de1, de2, de3, de4;

	while (1) {
		printf("[>] 1. 암호화\n[>] 2. 복호화\n[>] 3. 종료\n"); //메뉴출력

		scanf_s("%d", &sel);

		switch (sel)
		{
		case 1:
			printf("암호화 할 숫자를 입력하세요\n");
			scanf_s("%d", &en);

			if (en > 9999 || en < 1000) { // 입력값 확인
				printf("4자리숫자를 다시 입력하세요\n"); 
				break;
			}

			en1 = (en / 1000); //숫자 분리 및 암호화 작업
			en2 = (en/100) % 10;
			en3 = (en/10)%10;
			en4 = (en % 10);

			en1 = (en1 + 7) % 10;
			en2 = (en2 + 7) % 10;
			en3 = (en3 + 7) % 10;
			en4 = (en4 + 7) % 10;

			printf("암호문은 %d 입니다\n", (en4*1000+en3*100+en2*10+en1)); //암호문 출력
			break;

		case 2:
			printf("복호화 할 숫자를 입력하세요\n");
			scanf_s("%d", &de);

			if (de > 9999 || de < 1000) { // 입력값 확인
				printf("4자리숫자를 다시 입력하세요\n");
				break;
			}

			de1 = (de / 1000); //숫자 분리 및 복호화 작업
			de2 = (de / 100) % 10;
			de3 = (de / 10) % 10;
			de4 = (de % 10);

			de1 = (de1 + 3) % 10;
			de2 = (de2 + 3) % 10;
			de3 = (de3 + 3) % 10;
			de4 = (de4 + 3) % 10;

			printf("복호문은 %d 입니다\n", (de4 * 1000 + de3 * 100 + de2 * 10 + de1)); //복호문 출력
			break;

		case 3:
			return 0;

		}
	}
}