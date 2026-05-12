#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    printf("숫자 3개를 입력해주세요\n");
    int num1, num2, num3;
    int max = 0;
    scanf_s("%d %d %d", &num1, &num2, &num3);
    num1 > max ? max = num1 : max = max;
    num2 > max ? max = num2 : max = max;
    num3 > max ? max = num3 : max = max;
    printf("가장 큰 숫자 : %d", max);
    return 0;
}