//[백준] 1520 : 내리막 길

#include <stdio.h>
int map[501][501];
int dp[501][501];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;

int dfs(int x, int y)
{
	if (x == n - 1 && y == m - 1)
		return (1);
	if (dp[x][y] == -1)
	{
		dp[x][y] = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && map[x][y] > map[nx][ny])
				dp[x][y] += dfs(nx, ny);
		}
	}
	return dp[x][y];
}

int main()
{
	int result;

	// input
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
			dp[i][j] = -1;
		}
	}

	// dfs
	result = dfs(0, 0);

	// result
	printf("%d\n", result);
	return (0);
}