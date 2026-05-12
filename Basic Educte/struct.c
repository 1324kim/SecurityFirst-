#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
struct student {
	int num;
	char name[20];
	int student_number;
};

int main() {
	int max = 0;
	struct student st[3];
	struct student* ptr = st;
	char n[20];



	for (int i = 0; i < 3; i++) {

		printf("\n번호 입력 :");
		scanf("%d", &st[i].num); // &(ptr + i)->num 

		printf("\n이름 입력 :");
		scanf(" %s", &st[i].name);
		strcpy(st[i].name, n);

		printf("\n학번 입력 :");
		scanf("%d", &st[i].student_number);

		//printf("0x%x\n", &(ptr + i)->num);
		//printf("0x%x\n", &(*(&(ptr + i)))->num);

		if (st[i].student_number > max) {
			max = st[i].student_number;
		}
	}

	printf("\nMAX : %d\n", max);


	//for (int i = 0; i < 3; i++) {
		//pritnf("%s", n[i]);
	//}
	
	return 0;
}