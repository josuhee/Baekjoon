//[백준] 1149 : RGB거리

#include <stdio.h>
#define MIN(a,b) a<b?a:b

int cost[1000][3];
int dp[1000][3];

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < 3; j++) 
			scanf("%d", &cost[i][j]);

	dp[0][0] = cost[0][0];
	dp[0][1] = cost[0][1];
	dp[0][2] = cost[0][2];

	for (int i = 1; i < N; i++) {
		dp[i][0] = cost[i][0] + (MIN(dp[i - 1][1], dp[i - 1][2]));
		dp[i][1] = cost[i][1] + (MIN(dp[i - 1][0], dp[i - 1][2]));
		dp[i][2] = cost[i][2] + (MIN(dp[i - 1][0], dp[i - 1][1]));
	}

	N--;
	int result = MIN(dp[N][0], (MIN(dp[N][1], dp[N][2])));
	printf("%d\n", result);
	return 0;
}