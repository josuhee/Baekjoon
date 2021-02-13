//[백준] 1309 : 동물원

#include <stdio.h>

int dp[100000][3];

int main() {
	int N, m = 9901;
	scanf("%d", &N);

	dp[1][0] = dp[1][1] = dp[1][2] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % m;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % m;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % m;
	}

	printf("%d\n", (dp[N][0] + dp[N][1] + dp[N][2]) % m);

	return 0;
}