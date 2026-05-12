#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int vaild_passwd(char *pw) { //비밀번호 설정값이 올바른 입력인지 확인하는 함수
	if (strlen(pw) != 4) {
		return 1;
	}
	for (int i = 0; i < 4; i++){
		if (pw[i] < '0' || pw[i] > '9') return 1;
	}
	return 0;
}

void printmenu() { //메뉴출력 함수
	printf("1. 입금\n2. 출금\n3. 잔액확인\n4. 비번변경\n5. 종료\n");
}

void authpw(char *pw) {
	char input[10];
	int count = 0;
	while (1) { //비밀번호 인증로직

		scanf("%s", input);

		if (strcmp(pw, input) != 0) { 
			count++;
			printf("비번 틀렸습니다 %d/5\n", count);
			if (count == 5) exit(0); //5회 틀리면 종료, main 함수로 돌아가지 않고 exit 으로 즉시 프로그램 종료
			
		}
		else {
			break;
		}
	}
}


void in(int *money) { //입금함수
	int pl;
	printf("입금금액을 입력하세요\n");
	scanf("%d", &pl);
	*money += pl;
	printf("입금완료\n");
}

void out(int *money) { //출금함수
	int mi;
	printf("출금할 할 금액을 입력하세요\n");
	while (1) {
		scanf("%d", &mi);
		if (mi <= 0) {
			printf("올바른 금액을 입력하세요\n");
		}
		else if (*money < mi) {
			printf("현재 잔고는 %d 원 입니다 다시 입력해주세요\n", *money);
		}
		else {
			*money -= mi;
			printf("출금완료\n");
			break;
		}
	}
}

void ch_pw(char *pw) { //비밀번호변경 함수
	char new_passwd[10] = { "" };

	printf("변경할 비번을 입력하세요\n");
	while (1) {
		scanf("%s", new_passwd);
		if (strcmp(pw, new_passwd) == 0) { //strcmp 활용하여 기존 비밀번호와 새로운 비번이 일치하면 재입력 요청
			printf("기존 비번과 동일합니다 다시입력하세요\n");
		}
		else if (vaild_passwd(new_passwd)) { //비밀번호 입력값 검증함수 호출
			printf("4자리로 입력하세요\n");
		}
		else {
			strcpy(pw, new_passwd); //strcpy 활용하여 비밀번호 변경
			printf("변경완료\n");
			break;
		}
	}
}

int main() {
	int sel, pay = 0;
	char passwd[10] = { "" };

	printf("초기 비밀번호 4자리를 입력해주세요\n");
	while (1) {
		scanf("%s", passwd);

		if ( vaild_passwd(passwd) ) { //비밀번호 입력값 검증함수 호출
			printf("4자리로 다시 입력하세요");
		} 
		else {
			break;
		}
	}

	while (1) {
		printmenu(); //메뉴 출력함수 호출

		scanf("%d", &sel); //메뉴 입력

		if (sel == 5) return 0; // 종료옵션을 선택시 비밀번호 입력없이 즉시 종료

		printf("설정한 비밀번호를 입력하세요\n");
		
		authpw(passwd); // 비밀번호 일치 불일치를 확인하는 함수 호출
		
		switch (sel) 
		{
		case 1://입금로직
			in(&pay);
			break;

		case 2://출금로직
			out(&pay);
			break;

		case 3://잔액확인
			printf("남은 잔액 %d 원\n", pay);
			break;

		case 4://패스워드변경
			ch_pw(passwd);
			break;
		}
	}
}