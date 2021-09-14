//[백준] 1937 : 욕심쟁이 판다

#include <stdio.h>
#define MAX(a, b) a > b ? a : b

int n;
int map[501][501];
int dp[501][501];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

//dp + dfs
int dfs(int x, int y, int cnt)
{
	if (dp[x][y] == 0)
	{
		dp[x][y] = 1;
		int tmp = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n && map[x][y] < map[nx][ny])
				tmp = MAX(tmp, dfs(nx, ny, cnt + 1));
		}
		dp[x][y] += tmp;
	}
	return dp[x][y];
}

int main()
{
	int result = 0;

	//input
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);

	//algorithm
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			result = MAX(result, dfs(i, j, 1));

	//result
	printf("%d\n", result);
	return (0);
}