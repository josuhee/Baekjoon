//[백준] 14938 : 서강그라운드

#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#define INF 987654321
#define MAX(a, b) a > b ? a : b
using namespace std;

int item[101];
int visit[101];

int main()
{
	int n, m, r, x, y, cost;
	int tmp, max_item;
	max_item = 0;
	vector<pair<int, int>> adj[101];

	//input
	scanf("%d %d %d", &n, &m, &r);
	for (int i = 1; i <= n; i++)
		scanf("%d", &item[i]);
	for (int i = 0; i < r; i++)
	{
		scanf("%d %d %d", &x, &y, &cost);
		adj[x].push_back({y, cost});
		adj[y].push_back({x, cost});
	}

	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int>> pq;
	
	//각 정점에 대해 다익스트라를 사용하여
	//최대 아이템 수를 구함.
	for (int i = 1; i <= n; i++)
	{
		//초기화 및 정점 설정
		memset(visit, 0, sizeof(visit));
		tmp = 0;
		dist[i] = 0;
		pq.push({0, i});

		//다익스트라
		while (!pq.empty())
		{
			int cost = pq.top().first * -1;
			int here = pq.top().second;
			pq.pop();
			if (dist[here] < cost)
				continue;
			//해당 정점 방문 유무를 검사하여 더해주기
			if (!visit[here])
				tmp += item[here];
			visit[here] = 1;
			int size = adj[here].size();
			for (int i = 0; i < size; i++)
			{
				int there = adj[here][i].first;
				int nextDist = cost + adj[here][i].second;

				//기존 다익스트라 알고리즘에서 탐색범위 조건 추가
				if (dist[there] > nextDist && nextDist <= m)
				{
					dist[there] = nextDist;
					pq.push({nextDist * -1, there});
				}
			}
		}
		//최대 아이템 개수를 검사한 후 dist 초기화
		max_item = MAX(max_item, tmp);
		dist.clear();
		dist.assign(n + 1, INF);
	}
	//result
	printf("%d\n", max_item);
	return (0);
}