// [백준] 11048 : 이동하기

#include <stdio.h>
#define MAX(a,b) a>b?a:b

int n, m;
int map[1001][1001];

int main() {
	// input
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	// dp
	for (int i = 1; i <= n ;i++) {
		for (int j =1; j <= m;j++) {
			map[i][j] = map[i][j] + (MAX(map[i-1][j], (MAX(map[i][j-1], map[i-1][j-1]))));
		}
	}

	// result
	printf("%d\n", map[n][m]);
	return (0);
}