//[백준] 13023 : ABCDE

#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

vector<int> v[2000];
int visit[2000];

void dfs(int x, int cnt)
{
	visit[x] = 1;
	if (cnt == 4)
	{
		printf("1\n");
		exit(0);
	}
	int size = v[x].size();
	for (int i = 0; i < size; i++)
	{
		if (!visit[v[x][i]])
			dfs(v[x][i], cnt + 1);
	}
	visit[x] = 0;
}

int main()
{
	int n, m;
	int a, b;

	scanf("%d %d", &n, &m);
	while (m--)
	{
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		dfs(i, 0);
	printf("0\n");
	return (0);
}