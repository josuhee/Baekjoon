//[백준] 12865 : 평범한 배낭

#include <stdio.h>
#define MAX(a, b) a > b ? a : b

int dp[101][100001];
int item[101][2];

int main()
{
	int N, K;

	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &item[i][0], &item[i][1]);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			if (j < item[i][0])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = MAX(dp[i - 1][j], dp[i - 1][j - item[i][0]] + item[i][1]);
		}
	}
	printf("%d\n", dp[N][K]);
	return (0);
}