//[백준] 1789 : 수들의 합

#include <stdio.h>

int main()
{
	long long S, cnt, sum;

	cnt = sum = 0;
	scanf("%d", &S);

	for (long long num = 1;;num++)
	{
		sum += num;
		cnt++;
		if (sum > S)
		{
			cnt--;
			break;
		}
	}
	printf("%lld\n", cnt);
	return (0);
}