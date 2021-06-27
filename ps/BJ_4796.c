//[백준] 4796 : 캠핑

#include <stdio.h>

int main() {
	int L, P, V, cnt;
	for (int test_case = 1;; test_case++) {
		scanf("%d %d %d", &L, &P, &V);
		if (!L && !P && !V) break;

		cnt = (V / P) * L;
		V = V % P;
		cnt += V < L ? V : L;
		printf("Case %d: %d\n", test_case, cnt);
	}
	return 0;
}