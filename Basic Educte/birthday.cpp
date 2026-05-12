#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    printf("생년월일을 입력해주세요 ex)040101\n");
    int birth, year, mon, date;
    scanf_s("%d", &birth);
    year = (birth / 10000);
    mon = (birth-(year*10000)) / 100;
    date = birth % 100;

    year <= 25 ? year += 2000 : year += 1900;

    printf("날짜 %d년도 %d월 %d일", year, mon, date);
    return 0;
}