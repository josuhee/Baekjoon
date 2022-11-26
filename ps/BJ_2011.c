// [백준] 2011 : 암호코드

#include <stdio.h>
#include <string.h>

char cipher[5001];
int dp[5001];

int main() {
	// input
	scanf("%s", cipher);
	int size = strlen(cipher);

	// solution
	int result = 0;
	dp[0] = dp[1] = 1;
	if (cipher[0] - '0' != 0) {
		for (int i = 2; i <= size; i++) {
			int one = cipher[i - 1] - '0';
			int ten = cipher[i - 2] - '0';

			// invalid cipher
			if (one == 0 && (ten == 0 || ten >= 3)) {
				result = 0;
				break ;
			}

			// dp
			int num = ten * 10 + one;
			dp[i] = dp[i - 1] + dp[i - 2];
			if (one == 0)
				dp[i] -= dp[i - 1];
			if (num < 10 || 26 < num)
				dp[i] -= dp[i - 2];
			dp[i] = dp[i] % 1000000;
			result = dp[i];
		}
		if (size == 1)
			result = 1;
	}

	// output
	printf("%d\n", result);
	return (0);
}
