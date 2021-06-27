//[백준] 7576 : 토마토
#include <stdio.h>
#include <queue>
#define SIZE 1002
using namespace std;

int box[SIZE][SIZE];
bool visit[SIZE][SIZE];

/*
void printArr(int N, int M) {
	printf("\n");
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			printf("%d ", box[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
*/
int main() {
	int M, N;
	scanf("%d %d", &M, &N);

	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1) {
				q1.push(make_pair(i, j));
				visit[i][j] = true;
			}
		}
	}
	int cnt = 0;
	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,1,-1 };
	while (1) {
		while (!q1.empty()) {
			int x = q1.front().first;
			int y = q1.front().second;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 1 && ny >= 1 && nx <= N && ny <= M && box[nx][ny] != -1 && !visit[nx][ny]) {
					box[nx][ny] = 1;
					visit[nx][ny] = true;
					q2.push(make_pair(nx, ny));
				}

			}
			q1.pop();
		}
		//printArr(N, M);
		if (q2.empty()) break;
		cnt++;
		while (!q2.empty()) {
			int x = q2.front().first;
			int y = q2.front().second;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 1 && ny >= 1 && nx <= N && ny <= M && box[nx][ny] != -1 && !visit[nx][ny]) {
					box[nx][ny] = 1;
					visit[nx][ny] = true;
					q1.push(make_pair(nx, ny));
				}

			}
			q2.pop();
		}
		//printArr(N, M);
		if (q1.empty()) break;
		cnt++;
		
	}

	bool zero = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (box[i][j] == 0) {
				zero = true;
				break;
			}
		}
		if (zero) break;
	}

	if (zero) printf("-1\n");
	else printf("%d\n", cnt);

	return 0;
}
