//[백준] 11725 : 트리의 부모 찾기

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int parent[100001];
bool visit[100001];

bool compare(pair<int,int>a, pair<int, int>b) {
	if (a.first == b.first)
		return a.second < b.second;
	else return a.first < b.first;
}

int main() {
	int N;
	scanf("%d", &N);

	vector<pair<int,int>> v;
	int x, y;

	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &x, &y);
		v.push_back({ x, y });
		v.push_back({ y, x });
	}
	sort(v.begin(), v.end(), compare);
	int size = v.size(), right, left, mid;

	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		visit[node] = true;

		left = 0; right = size - 1;
		while (left < right) {
			mid = (left + right) / 2;
			if (v[mid].first >= node) right = mid;
			else left = mid + 1;
		}
		for (int i = right; i < size; i++) {
			if (v[i].first != node) break;
			if (visit[v[i].second] == false) {
				parent[v[i].second] = v[i].first;
				q.push(v[i].second);
			}
		}
	}

	for (int i = 2; i <= N; i++)
		printf("%d\n", parent[i]);

	return 0;
}