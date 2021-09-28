//[백준] 14500 : 테트로미노

#include <stdio.h>
#include <string.h>
#define MAX(a, b) a > b ? a : b

int n, m;
int result;
int map[501][501];
int visit[500][500];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y, int cnt, int sum)
{
	if (cnt == 4)
	{
		result = MAX(result, sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < m \
			&& !visit[nx][ny])
		{
			visit[x][y] = 1;
			dfs(nx, ny, cnt + 1, sum + map[nx][ny]);
			visit[nx][ny] = 0;
		}
	}
}

void func(int x, int y)
{
	int sum = map[x][y];

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < m)
			sum += map[nx][ny];
	}

	if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
		result = MAX(result, sum);
	else
	{
		int tmp;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			tmp = sum - map[nx][ny];
			result = MAX(result, tmp);
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visit[i][j] = 1;
			dfs(i, j, 1, map[i][j]);
			visit[i][j] = 0;
			func(i, j);
		}
	}
	printf("%d\n", result);
	return (0);
}