//[백준] 1463 : 1로 만들기

#include <stdio.h>
#define SIZE 1000001
#define MIN(a,b) a<b?a:b

int dp[SIZE];

int main() {
	int N;
	scanf("%d", &N);

	dp[1] = 0;
	dp[2] = dp[3] = 1;

	int min;
	for (int i = 4; i <= N; i++) {
		min = dp[i - 1] + 1;
		if (i % 3 == 0) {
			min = MIN(min, dp[i / 3] + 1);
		}
		if (i % 2 == 0) {
			min = MIN(min, dp[i / 2] + 1);
		}
		dp[i] = min;
	}

	printf("%d\n", dp[N]);
	return 0;
}