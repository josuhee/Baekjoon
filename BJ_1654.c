//[백준] 1654 : 랜선 자르기

#include <stdio.h>

unsigned int lan[10000];
int main() {
	int K, N;
	unsigned int max = 0;
	scanf("%d %d", &K, &N);

	for (int i = 0; i < K; i++) {
		scanf("%u", &lan[i]);
		if (max < lan[i]) max = lan[i];
	}

	unsigned int left, right, mid, length = 0;
	int cnt;
	right = max;
	left = 1;
	while (left <= right) {
		cnt = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < K; i++)
			cnt += lan[i] / mid;
		if (cnt >= N) {
			left = mid + 1;
			if (mid > length)
				length = mid;
		}
		else
			right = mid - 1;
	}
	printf("%u\n", length);
	return 0;
}