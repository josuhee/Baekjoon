//[백준] 1932 : 정수 삼각형

#include <stdio.h>
#define MAX(a, b) a > b ? a : b

int dp[501][501];
int num[501][501];

int main()
{
	int N;

	//input
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			scanf("%d", &num[i][j]);

	//dp
	dp[0][0] = num[0][0];
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			
			if (j == 0)
				dp[i][j] = dp[i - 1][j] + num[i][j];
			else
				dp[i][j] = num[i][j] + (MAX(dp[i - 1][j], dp[i - 1][j - 1]));
		}
	}

	//result
	int max = 0;
	for (int i = 0;i<N;i++)
		max = MAX(max, dp[N-1][i]);
	printf("%d\n", max);
	return (0);
}