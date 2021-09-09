//[백준] 4153 : 직각삼각형

#include <stdio.h>

void swap_int(int *n, int *m)
{
	int tmp = *n;
	*n = *m;
	*m = tmp;
}

int main()
{
	int a, b, c;

	while (1)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (!a && !b && !c)
			break;
		if (a > c) swap_int(&a, &c);
		if (b > c) swap_int(&b, &c);
		if (a * a + b * b == c * c)
			printf("right\n");
		else
			printf("wrong\n");
	}
}