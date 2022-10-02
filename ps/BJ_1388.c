// [백준] 1388 : 바닥 장식

#include <stdio.h>

char map[51][51];
int n, m;

void verti(int x, int y) {
	for (int i = x; i < n; i++) {
		if (map[i][y] != '|') break;
		map[i][y] = '.';
	}
}

void hori(int x, int y) {
	for (int j = y; j < m; j++) {
		if (map[x][j] != '-') break;
		map[x][j] = '.';
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", map[i]);

	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '|') {
				verti(i, j);
				result++;
			}
			if (map[i][j] == '-') {
				hori(i, j);
				result++;
			}
		}
	}

	printf("%d\n", result);
	return (0);
}