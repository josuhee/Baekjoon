//[백준] 14502 : 연구소

#include <stdio.h>
#include <string.h>
#include <vector>
#define MAX(a,b) a>b?a:b
using namespace std;
 
int N, M, result;
int map[8][8];
int visit[8][8];
vector<pair<int, int>> v;
 
//바이러스 퍼트리는 dfs
int dfs(int x, int y) {
    visit[x][y] = 1;
    if (x - 1 >= 0 && visit[x - 1][y] == 0 && map[x - 1][y] == 0) {
        dfs(x - 1, y);
    }
    if (y - 1 >= 0 && visit[x][y - 1] == 0 && map[x][y - 1] == 0) {
        dfs(x, y - 1);
    }
    if (x + 1 < N && visit[x + 1][y] == 0 && map[x + 1][y] == 0) {
        dfs(x + 1, y);
    }
    if (y + 1 < M && visit[x][y+1] == 0 && map[x][y+1] == 0) {
        dfs(x, y + 1);
    }
    return 0;
}
 
//벽 3개 고르기
int select(int cnt) {
    if (cnt == 3) {
        memset(visit, 0, sizeof(visit));//방문기록 초기화
        int size = v.size();
        for (int i = 0; i < size; i++) {
            dfs(v[i].first, v[i].second);
        }
        int cnt = 0;
 
        //바이러스가 퍼지지 않은 곳 count
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 0 && visit[i][j] == 0) 
                    cnt++;
            }
        }
 
        //최대값 기록
        result = MAX(result, cnt);
    }
    else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 0) {
                    map[i][j] = 1;
                    select(cnt + 1);
                    map[i][j] = 0;
                }
            }
        }
    }
    
 
    return 0;
}
 
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2) v.push_back(make_pair(i, j));
        }
    }
    select(0);
    printf("%d\n", result);
    return 0;
}