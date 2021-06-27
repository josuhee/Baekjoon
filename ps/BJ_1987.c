//[백준] 1987 : 알파벳

#include <stdio.h>
#define MAX(a,b) a>b?a:b
 
int alpha[26];
int table[20][20];
int result;
int r, c;
 
void dfs(int x, int y, int cnt) {
 
    //알파벳 체크해주고 탐색 개수 검사
    alpha[table[x][y]] = 1;
    result = MAX(result, cnt);
 
    int dx[] = { 1,-1,0,0 };
    int dy[] = { 0,0,1,-1 };
 
    //상하좌우 이동
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
 
        //조건에 맞다면 방문, 방문이 끝나면 기록 해제
        if (nx >= 0 && ny >= 0 && nx < r && ny < c && !alpha[table[nx][ny]]) {
            dfs(nx, ny, cnt + 1);
            alpha[table[nx][ny]] = 0;
        }
    }
}
 
int main() {
    char str[25];
    scanf("%d %d", &r, &c);
 
    //보드 입력
    for (int i = 0; i < r; i++) {
        scanf("%s", str);
        for (int j = 0; j < c; j++) {
            table[i][j] = str[j] - 'A';
        }
    }
 
    //dfs, 좌측 상단 검사
    dfs(0, 0, 1);
 
    //결과 출력
    printf("%d\n", result);
    return 0;
}
