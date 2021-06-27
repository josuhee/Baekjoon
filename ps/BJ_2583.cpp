//[백준] 2583 : 영역 구하기

#include <stdio.h>
#include <algorithm>
using namespace std;
 
int arr[100][100];
int result[100];
int M, N, K;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
 
//깊이 우선 탐색
//value값을 삽입
int dfs(int x, int y, int value) {
    arr[x][y] = value;
 
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
 
        if (nx >= 0 && ny >= 0 && nx < M && ny < N && arr[nx][ny] == 0)
            dfs(nx, ny, value);
    }
    return 0;
}
 
int main() {
    scanf("%d %d %d", &M, &N, &K);
    
    pair<int, int> a;
    pair<int, int> b;
 
    //K개의 직사각형
    while (K--) {
        scanf("%d %d %d %d", &a.first, &a.second, &b.first, &b.second);
 
        for (int i = a.second; i < b.second; i++) 
            for (int j = a.first; j < b.first; j++)
                arr[i][j] = 1;
    }
    
    //영역 검사하기
    int cnt = 1;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 0) {
                cnt++;
                dfs(i, j, cnt);
            }
        }
    }
 
    //채운 영역의 크기 count
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            result[arr[i][j]]++;
        }
    }
 
    //정렬하고 결과 
    sort(result + 2, result + cnt + 1);
    printf("%d\n", cnt - 1);
    for (int i = 2; i <= cnt; i++)
        printf("%d ", result[i]);
    printf("\n");
 
    return 0;
}
