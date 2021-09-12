//[백준] 2589 : 보물섬

#include <iostream>
#include <queue>
#include <string.h>
#define MAX(a,b) a>b?a:b
using namespace std;

int visit[50][50];
string map[50];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, result;

void bfs(int i, int j)
{
	//init
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> q;
	q.push({i, j});
	visit[i][j] = 1;

	//bfs
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		result = MAX(result, visit[x][y]);
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m \
				&& map[nx][ny] == 'L' && visit[nx][ny] == 0)
			{
				visit[nx][ny] = visit[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	//input
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> map[i];

	//bfs & burte force
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'L')
				bfs(i, j);
		}
	}

	//output
	cout << result - 1 << "\n";

	return (0);
}