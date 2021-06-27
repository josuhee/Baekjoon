//[백준] 2667 : 단지번호붙이기

#include <stdio.h>
#include <algorithm>
using namespace std;
 
int arr[25][25];
int building[350];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int N;
 
int dfs(int x, int y, int cnt) {
    //단지번호 저장
    arr[x][y] = cnt;
 
    for (int i = 0; i < 4; i++) {
        //좌표값을 상하좌우로
        int nx = x + dx[i];
        int ny = y + dy[i];
 
        //전체범위를 넘어가지 않으면서,
        //인덱스값이 1일 때 해당 좌표로 이동
        if (nx >= 0 && ny >= 0 && nx < N && ny < N && arr[nx][ny] == 1)
            dfs(nx, ny, cnt);
    }
    return 0;
}
 
 
int main() {
    //초기 단지번호 : 2
    int cnt = 2;
 
    scanf("%d", &N);
 
    //입력받기
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%1d", &arr[i][j]);
 
    //단지번호가 1인 것만 dfs 돌리기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 1) {
                dfs(i, j, cnt);
                cnt++;
            }
        }
    }
 
    //단지번호가 2이상인 단지의 집 수 구하기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] > 1)
                building[arr[i][j] - 2]++;
        }
    }
    cnt -= 2;
 
    //정렬
    sort(building, building + cnt);
 
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
        printf("%d\n", building[i]);
    return 0;
}
