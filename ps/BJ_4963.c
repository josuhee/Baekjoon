//[백준] 4963 : 섬의 개수

#include <stdio.h>

int arr[50][50];
int n, m;

int dfs(int x, int y) {
	arr[x][y] = 0;

	if (x - 1 >= 0 && arr[x - 1][y]) dfs(x - 1, y);
	if (x + 1 < n && arr[x + 1][y]) dfs(x + 1, y);
	if (y - 1 >= 0 && arr[x][y - 1]) dfs(x, y - 1);
	if (y + 1 < m && arr[x][y + 1]) dfs(x, y + 1);
	if (x - 1 >= 0 && y - 1 >= 0 && arr[x - 1][y - 1]) dfs(x - 1, y - 1);
	if (x + 1 < n && y - 1 >= 0 && arr[x + 1][y - 1]) dfs(x + 1, y - 1);
	if (x - 1 >= 0 && y + 1 < m && arr[x - 1][y + 1]) dfs(x - 1, y + 1);
	if (x + 1 < n && y + 1 < m && arr[x + 1][y + 1]) dfs(x + 1, y + 1);
	
	return 0;
}


int main() {
	int cnt;
	while (1) {
		cnt = 0;
		scanf("%d %d", &m, &n);

		if (!m && !n) break;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &arr[i][j]);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);
	}
	return 0;
}