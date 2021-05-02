//[백준] 9465 : 스티커

#include <stdio.h>
#define MAX(a,b) a>b?a:b

int dp[2][100001];
int sticker[2][100001];

int main() {
	int TC, n;

	scanf("%d", &TC);
	for (int test_case = 0; test_case < TC; test_case++) {
		scanf("%d", &n);

		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &sticker[i][j]);

		if (n == 1)
			printf("%d\n", MAX(sticker[0][1], sticker[1][1]));
		else if (n == 2)
			printf("%d\n", MAX(sticker[0][1] + sticker[1][2], sticker[1][1] + sticker[0][2]));
		else {
			dp[0][1] = sticker[0][1];
			dp[1][1] = sticker[1][1];
			dp[0][2] = dp[1][1] + sticker[0][2];
			dp[1][2] = dp[0][1] + sticker[1][2];
			for (int i = 3; i <= n; i++) {
				int tmp = MAX(dp[0][i - 2], dp[1][i - 2]);
				dp[0][i] = sticker[0][i] + (MAX(tmp, dp[1][i - 1]));
				dp[1][i] = sticker[1][i] + (MAX(tmp, dp[0][i - 1]));
			}
			printf("%d\n", MAX(dp[0][n], dp[1][n]));
		}
	}
	return 0;
}