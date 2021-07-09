//[백준] 2553 : 마지막 팩토리얼 수

#include <stdio.h>

int main()
{
	int N;
	long long fact;

	fact = 1;
	scanf("%d", &N);
	for (int i=1; i<= N; i++)
	{
		fact %= 10000000;
		fact *= i;
		while (fact % 10 == 0)
			fact /= 10;
	}
	printf("%d\n", fact % 10);
	return (0);
}