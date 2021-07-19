//[백준] 11052 : 카드 구매하기

#include <stdio.h>
#define MAX(a, b) a > b ? a : b

int card[1001];
int dp[1001];

int main()
{
	int N;

	//input
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &card[i]);
	
	//dp
	for (int i = 1; i <= N; i++)
		for (int j = i; j <= N; j++)
			dp[j] = MAX(dp[j], dp[j - i] + card[i]);
	
	//output
	printf("%d\n", dp[N]);
	return (0);
}