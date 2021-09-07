//[백준] 11057 : 오르막 수

#include <stdio.h>
#define MOD 10007

int dp[1001][10];

int main()
{
	int N;

	//input
	scanf("%d", &N);

	//init
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	//dp
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j != 0)
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	//result
	int result = 0;
	for (int i = 0; i < 10; i++)
		result = (result + dp[N][i]) % MOD;
	printf("%d\n", result);
	return (0);
}