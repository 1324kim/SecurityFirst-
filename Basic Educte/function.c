#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	char arr[20] = {""};
	int count = 0;

	scanf("%s", arr);

	printf("입력받은 문자는 %s 입니다\n", arr);

	for (int i = 0; i < 20; i++) {
		if (*(arr+i) != '\0') {
			count++;
		}
	}

	//for (int i = 0; *(arr + i) != '\0'; i++);
	//	printf ~~~~

	//*(arr+i) == arr[i]

	printf("문자의 개수는 %d개 입니다\n", count);
	return 0;
}
