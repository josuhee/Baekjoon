// [백준] 1010 : 다리 놓기

#include <stdio.h>
#include <string.h>

int dp[31][31];

int main()
{
	int TC;
	int n, m;
	int size, result;

	scanf("%d", &TC);
	for (int test_case = 0; test_case < TC; test_case++)
	{
		scanf("%d %d", &n, &m);
		memset(dp, 0, sizeof(dp));
		size = m - n;

		// init
		for (int i = 1; i <= size + 1; i++)
			dp[1][i] = 1;
		// dp
		for (int i = 2; i <= n; i++)
			for (int j = i; j <= i + size; j++)
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
		// result
		result = 0;
		for (int i = n; i <= m; i++)
			result += dp[n][i];
		printf("%d\n", result);
	}
	return (0);
}