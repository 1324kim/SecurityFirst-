#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void MAX(int** ptr2, int arr[]) {
	for (int i = 0; i < 5; i++){
		if (arr[i] > **ptr2) {
			**ptr2 = arr[i];
		}
	}
}

int main() {
	int arr[5] = { 0 };
	int max = 0;
	int* ptr1 = &max;
	int** ptr2 = &ptr1;
	printf("5개의 자연수를 입력하세요 : ");

	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
	}


	MAX(&ptr1, arr);
	printf("최대값은 %d 입니다", max);
	return 0;
}