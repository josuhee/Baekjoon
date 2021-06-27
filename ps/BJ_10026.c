//[백준] 10026 : 적록색약

#include <stdio.h>
#include <string.h>

int N;
int arr[100][100];
int visit[100][100];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int dfs(int color, int x, int y) {
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < N && arr[nx][ny] == color && !visit[nx][ny]) {
			dfs(color, nx, ny);
		}
	}
	return 0;
}

int RedGreen(int x, int y) {
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < N && (arr[nx][ny] == 1 || arr[nx][ny] == 2) && !visit[nx][ny]) {
			RedGreen(nx, ny);
		}
	}
	return 0;
}


int main() {
	scanf("%d", &N);

	char str[101];
	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		for (int j = 0; j < N; j++) {
			if (str[j] == 'R') arr[i][j] = 1;
			else if (str[j] == 'G') arr[i][j] = 2;
			else arr[i][j] = 3;
		}
	}

	int red = 0, green = 0, blue = 0, red_green = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && !visit[i][j]) {
				dfs(1, i, j);
				red++;
			}
			if (arr[i][j] == 2 && !visit[i][j]) {
				dfs(2, i, j);
				green++;
			}
			if (arr[i][j] == 3 && !visit[i][j]) {
				dfs(3, i, j);
				blue++;
			}
		}
	}
	
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((arr[i][j] == 1 || arr[i][j] == 2) && !visit[i][j]) {
				RedGreen(i, j);
				red_green++;
			}
		}
	}

	int result1 = red + green + blue;
	int result2 = red_green + blue;
	printf("%d %d\n", result1, result2);
	return 0;
}