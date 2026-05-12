#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int account_count = 0;
int maxbook = 0;

struct account {
	char id[15]; //널 문자 까지 포함하여 선언
	char pw[15];
};

struct books {
	char title[50]; //책제목
	int is_borrowed; //책이 빌려졌는지 아닌지 확인하는 변수
	char borrower[15]; //어떤 아이디가 빌렸는지
};

struct account acc[20];
struct books b[100];


void creat_account() {

	printf("====================================\n");
	
	if (account_count > 20) {
		printf("더 이상 계정을 생성할 수 없습니다\n");
		return;
	}

	while (1) { //아이디, 비번 입력이 올바른지 확인하는 반복문
		printf("계정을 생성합니다\n아이디를 입력하세요(14글자이내)\n");
		scanf("%s", &acc[account_count].id);

		if (strlen(acc[account_count].id) == 0 || strlen(acc[account_count].id) > 14){
			printf("14자리 이내로 입력하세요\n");
			continue;
		}

		printf("비밀번호를 입력해주세요(14글자이내)\n");
		scanf("%s", &acc[account_count].pw);

		if (strlen(acc[account_count].pw) == 0 || strlen(acc[account_count].pw) > 14) {
			printf("14자리 이내로 입력하세요\n");
			continue;
		}

		break;
	}
	
	printf("%s 계정이 생성되었습니다\n", acc[account_count].id);

	account_count++;
}

void add_book() {

	printf("================================================\n");
	if (maxbook > 100) {
		printf("책을 더 추가할 수 없습니다\n");
		return;
	}

	printf("추가할실 책 제목을 입력하세요\n");
	scanf("%s", &b[maxbook].title); //books 구조체에 책 제목 추가
	b[maxbook].is_borrowed = 0; //방금 추가된 책이기 때문에 안빌려진 책으로 값 설정
	printf("책이 추가되었습니다: %s\n", b[maxbook].title);

	maxbook++;

}

int verify_id(char* id) {

		for (int i = 0; i < account_count; i++) {
			if (strcmp(acc[i].id, id) == 0)
				return i;
		}
		return -1;
}

void rent_book() {
	printf("================================\n");

	char book_name[50];
	int avail = 0;

	for (int i = 0; i < maxbook; i++){ 
		if (!b[i].is_borrowed) { //대출가능한 책이 하나라도 있으면 avail 값을 1로 만들고 탈출
			avail = 1;
			break;
		}
	}
	if (avail != 1) {
		printf("대출가능한 책이 없습니다\n");
		return;
	}
	// avail 값이 0이면 대출가능한 책이 없는것이므로 함수 탈출

	int idx;
	char id_input[15];

	while (1) { //존재하는 아이디인지 확인, 존재하지않는 다면 continue 를 통해 재입력
		printf("아이디를 입력하세요\n");
		scanf("%s", id_input);

		idx = verify_id(id_input);

		if (idx == -1) {
			printf("존재하지않는 아이디 입니다\n");
			continue;
		}
		break;
	}

	int fail = 0;
	char pw_input[15];

	while (1) {
		printf("비밀번호를 입력하세요\n");
		scanf("%s", pw_input);

		if (strcmp(acc[idx].pw, pw_input) != 0) {
			fail++;
			printf("비밀번호 틀렸습니다 [%d/5]", fail);
			if (fail > 5) {
				printf("로그인 실패\n");
				exit(0);
			}
			continue;
		}
		else printf("로그인 성공"); break;
	}
	
	printf("책 제목을 입력하세요\n");
	scanf("%s", book_name);

	int found = 0;
	for (int i = 0; i < maxbook; i++) {
		if (strcmp(b[i].title, book_name) == 0) {
			printf("대여에 성공하셨습니다\n");
			b[i].is_borrowed = 1;
			found = 1;
			break;
		}
	}
	if (!found) {
		printf("해당책을 찾을 수 없습니다\n");
	}
}

void possible_book() {
	printf("===============================\n");

	for (int i = 0; i < maxbook; i++) {
		if (b[i].is_borrowed == 0)
			printf("%s\n", b[i].title);
	}
}

void impossible_book() {
	printf("===============================\n");

	for (int i = 0; i < maxbook; i++) {
		if (b[i].is_borrowed == 1)
			printf("%s\n", b[i].title);
	}
}

void search() {
	printf("===============================\n");

	int found = 0;
	char search_name[50];

	printf("검색하실 책 제목을 입력하세요\n");
	scanf("%s", search_name);

	for (int i = 0; i < maxbook; i++){
		if (strcmp(b[i].title, search_name) == 0) {
			printf("해당책은 존재합니다 : %s\n", search_name);
			found = 1;
			break;
		}
	}
	if (!found) {
		printf("해당책은없어요\n");
	}
}


int main() {
	int select;

	while (1) {

		printf("==========================\n");
		printf("1. 계정생성\n");
		printf("2. 책 추가\n");
		printf("3. 책 대출\n");
		printf("4. 대출 가능 목록\n");
		printf("5. 대출 불가 목록\n");
		printf("6. 책 검색\n");
		printf("7. 종료\n");
		printf("==========================\n");
		printf(">");
		scanf("%d", &select);

		switch (select) {

		case 1: creat_account(); break;
		case 2: add_book(); break;
		case 3: rent_book(); break;
		case 4: possible_book(); break;
		case 5: impossible_book(); break;
		case 6: search(); break;
		case 7: printf("시스템종료");  exit(0);
		default: printf("잘못입력했습니다 다시 입력 하세요\n");

		}

	}


	return 0;
}