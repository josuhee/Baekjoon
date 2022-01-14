//[백준] 14888 : 연산자 끼워넣기

#include <stdio.h>
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b

int n;
int num[11], operator[4];
int max = -1234567890;
int min = 1234567890;

void func(int plus, int minus, int mul, int div, int result, int cnt)
{
	if (cnt == n)
	{
		max = MAX(max, result);
		min = MIN(min, result);
		return ;
	}
	if (plus < operator[0])
		func(plus + 1, minus, mul, div, result + num[cnt], cnt + 1);
	if (minus < operator[1])
		func(plus, minus + 1, mul, div, result - num[cnt], cnt + 1);
	if (mul < operator[2])
		func(plus, minus, mul + 1, div, result * num[cnt], cnt + 1);
	if (div < operator[3])
		func(plus, minus, mul, div + 1, result / num[cnt], cnt + 1);
}

int main()
{
	// input
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	for (int i = 0; i < 4; i++)
		scanf("%d", &operator[i]);

	// soluation
	func(0, 0, 0, 0, num[0], 1);

	// result
	printf("%d\n%d\n", max, min);
	return (0);
}