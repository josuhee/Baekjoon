//[백준] 10162 : 전자레인지

#include <stdio.h>

int main() {
	int t;
	int btn[] = { 300,60,10 };
	int cnt[3] = { 0, };

	scanf("%d", &t);
	if (t % 10 == 0) {
		for (int i = 0; i < 3; i++) {
			if (t >= btn[i]) {
				t -= btn[i];
				cnt[i]++;
				i--;
			}
			if (t == 0)
				break;
		}
		//결과 출력
		printf("%d %d %d\n", cnt[0], cnt[1], cnt[2]);
	}
	else
		printf("-1\n");
	return 0;
}