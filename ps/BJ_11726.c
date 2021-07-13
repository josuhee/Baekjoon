//[백준] 11726 : 2xn 타일링

#include <stdio.h>
#define MOD 10007

int dp[1001][2];

int main()
{
	int n;

	scanf("%d", &n);
	dp[1][0] = 1;
	dp[1][1] = 0;
	dp[2][0] = 1;
	dp[2][1] = 1;
	for (int i = 3; i <= n; i++)
	{
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
		dp[i][1] = (dp[i - 2][0] + dp[i - 2][1]) % MOD;
	}
	printf("%d\n", (dp[n][0] + dp[n][1]) % MOD);
	return (0);
}