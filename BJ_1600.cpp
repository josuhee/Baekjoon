//[백준] 1600 : 말이 되고픈 원숭이

#include <stdio.h>
#include <queue>
using namespace std;
 
int arr[200][200];
bool visit[200][200][32];
int k, w, h;
 
typedef struct {
    int x;
    int y;
    int horse;
}st;
 
//각각 말과 원숭이가 움직일 수 있는 좌표
int h_move[][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1} };
int m_move[][2] = { {1,0},{0,1},{-1,0},{0,-1} };
 
int main() {
    scanf("%d %d %d", &k, &w, &h);
 
    //장애물이 있는 곳은 -1
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j]) arr[i][j] = -1;
        }
    }
 
    //구조체를 자료형으로 큐를 만듦
    queue<st> q;
    q.push({ 0,0,0 });
    visit[0][0][0] = true;
    int nx, ny;
 
    //bfs
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int horse = q.front().horse;
        q.pop();
 
        //말 처럼 움직인 것이 K번 미만일 때
        //말 처럼 움직이기
        if (horse < k) {
            //8방향으로
            for (int i = 0; i < 8; i++) {
                nx = x + h_move[i][0];
                ny = y + h_move[i][1];
 
                //범위 내 좌표면서 장애물이 아니고 방문한 곳이 아니라면
                if (nx >= 0 && ny >= 0 && nx < h && ny < w) {
                    if (arr[nx][ny] != -1 && !visit[nx][ny][horse + 1]) {
                        visit[nx][ny][horse + 1] = true;
                        arr[nx][ny] = arr[x][y] + 1;
                        q.push({ nx,ny,horse + 1 });
                    }
                }
 
                //도착한 좌표가 도착지점(오른쪽 아래)일 경우
                if (nx == h - 1 && ny == w - 1) {
                    printf("%d\n", arr[nx][ny]);
                    return 0;
                }
            }
        }
 
        //원숭이 처럼 움직이기
        //4방향으로
        for (int i = 0; i < 4; i++) {
            nx = x + m_move[i][0];
            ny = y + m_move[i][1];
 
            //범위 내 좌표면서 장애물이 아니고 방문한 곳이 아니라면
            if (nx >= 0 && ny >= 0 && nx < h && ny < w) {
                if (arr[nx][ny] != -1 && !visit[nx][ny][horse]) {
                    visit[nx][ny][horse] = true;
                    arr[nx][ny] = arr[x][y] + 1;
                    q.push({ nx,ny,horse });
                }
            }
 
            //도착한 좌표가 도착지점(오른쪽 아래)일 경우
            if (nx == h - 1 && ny == w - 1) {
                printf("%d\n", arr[nx][ny]);
                return 0;
            }
        }
    }
    /*bfs문을 탈출했다면 목적지에 도달하지 못했다는 것*/
 
    //출발지점과 도착지점이 같다면 0
    //아니라면 -1
    if (w == 1 && h == 1) printf("0\n");
    else printf("-1\n");
    return 0;
}