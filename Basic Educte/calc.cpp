#include <stdio.h>
int main() {
	int num1, num2;
	int max = 0, min = 0;
	char cal;

	scanf_s("%d %d", &num1, &num2);
	scanf_s(" %c", &cal);
	
	if (num1 > num2) {
		max = num1;
		min = num2;
	}
	else if(num2 > num1) {
		max = num2;
		min = num1;
	}

	switch (cal) 
	{
		case '+':
			printf("%d", (max + min));
			break;
		case '-':
			printf("%d", (max - min));
			break;
		case '*':
			printf("%d", (max * min));
			break;
		case '/':
			printf("%d", (max / min));
			break;
	}


	return 0;
	}