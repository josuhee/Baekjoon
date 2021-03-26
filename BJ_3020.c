//[백준] 3020 : 개똥벌레

#include <stdio.h>
#define SIZE 500001

int length[SIZE];

int main() {
	int N, H;
	scanf("%d %d", &N, &H);
	
	int num;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		if (i % 2) length[H - num]++;
		else length[num]--;
	}
	N /= 2;
	int min = N, cnt = 1, curr = N;
	for (int i = 1; i < H; i++) {
		curr += length[i];
		if (curr == min) cnt++;
		else if (curr < min) {
			min = curr;
			cnt = 1;
		}
	}
	printf("%d %d\n", min, cnt);

	return 0;
}