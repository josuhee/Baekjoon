//[백준] 15686 : 치킨 배달

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#define MIN(a,b) a<b?a:b
using namespace std;

int N, M, delete_cnt, chick_size;
int arr[50][50];
int visit[13];
int result = 1000000;
vector<pair<int, int>> house, chick;

int func() {
	int size = house.size(), distance, result = 0;
	for (int i = 0; i < size; i++) {
		distance = 100;
		int x = house[i].first;
		int y = house[i].second;
		for (int j = 0; j < chick_size; j++) {
			if (visit[j]) {
				int tmp = abs(x - chick[j].first) + abs(y - chick[j].second);
				distance = MIN(distance, tmp);
			}
		}
		result += distance;
	}
	
	return result;
}

int select(int idx, int cnt) {
	if (cnt == M) {
		int tmp =func();
		result = MIN(result, tmp);
	}
	
	if (idx == chick_size) return 0;

	visit[idx] = 1;
	select(idx + 1, cnt + 1);
	visit[idx] = 0;
	select(idx + 1, cnt);
	
	return 0;
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) house.push_back(make_pair(i,j));
			if (arr[i][j] == 2) chick.push_back(make_pair(i, j));
		}
	}
	chick_size = chick.size();
	select(0, 0);

	printf("%d\n", result);

	return 0;
}