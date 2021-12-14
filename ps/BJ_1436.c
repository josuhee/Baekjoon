//[백준] 1436 : 영화감독 숌
#include <stdio.h>

int main()
{
	int N;
	int cnt = 0;

	scanf("%d", &N);
	for (int tc = 666;;tc++)
	{
		int tmp = tc;

		// check 666
		while (tmp != 0)
		{
			if (tmp % 1000 == 666)
			{
				cnt++;
				break;
			}
			else tmp /= 10;
		}

		//result
		if (cnt == N)
		{
			printf("%d\n", tc);
			break;
		}
	}

	return 0;
}