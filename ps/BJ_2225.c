// [백준] 2225 : 합분해

#include <stdio.h>
#define MOD 1000000000

int dp[201][201];

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; i++)
		dp[1][i] = 1;
	
	for (int i = 2; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int m = 0; m <= j; m++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j - m]) % MOD;
			}
		}
	}

	printf("%d\n", dp[k][n]);
	return (0);
}