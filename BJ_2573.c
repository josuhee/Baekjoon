//[백준] 2573 : 빙산

#include <stdio.h>
#include <string.h>

int n, m;
int map[300][300];
int visit[300][300];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y)
{
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx >= 0 && ny >= 0 && nx < n && ny < m && map[nx][ny] != 0 && !visit[nx][ny])
			dfs(nx, ny);
	}
}

void melt_map()
{
	int zero[300][300];
	int tmp;

	memset(zero, 0, sizeof(zero));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = dx[k] + i;
					int ny = dy[k] + j;

					if (nx >= 0 && ny >= 0 && nx < n && ny < m)
						zero[nx][ny]++;
				}
			}
		}
	}
	//melt
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp = map[i][j] - zero[i][j];
			tmp = tmp > 0 ? tmp : 0;
			map[i][j] = tmp;
		}
	}
}

int zero_map()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] != 0)
				return (1);
		}
	}
	return (0);
}

int main()
{
	int cnt, year;

	//input
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);

	year = 0;
	while (zero_map())
	{
		cnt = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] != 0 && !visit[i][j])
				{
					dfs(i, j);
					cnt++;
				}
			}
		}
		if (cnt >= 2)
			break;
		melt_map();
		year++;
	}
	if (cnt >= 2)
		printf("%d\n", year);
	else
		printf("0\n");
	return (0);
}