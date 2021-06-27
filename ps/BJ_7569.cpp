//[C++] 백준 7569 : 토마토

#include <stdio.h>
#include <queue>
#define MAX(a,b) a>b?a:b
using namespace std;
 
typedef struct {
    int x;
    int y;
    int z;
}st;
 
int box[100][100][100];
 
int main() {
    int M, N, H;
    scanf("%d %d %d", &M, &N, &H);
 
    queue<st> q;
 
    //값 입력받기
    //1이라면 큐에 삽입
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                scanf("%d", &box[i][j][k]);
                if (box[i][j][k] == 1) q.push({ i,j,k });
            }
        }
    }
 
    //인접부분 좌표 설정
    int dx[] = { 1,-1,0,0,0,0 };
    int dy[] = { 0,0,1,-1,0,0 };
    int dz[] = { 0,0,0,0,1,-1 };
    int x, y, z, nx, ny, nz, max = 0;
 
    //토마토 검사
    while (!q.empty()) {
        //큐의 첫번째 요소의 좌표
        x = q.front().x;
        y = q.front().y;
        z = q.front().z;
 
        //6방향으로 검사
        for (int i = 0; i < 6; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            nz = z + dz[i];
 
            //조건에 충족한다면 큐에 좌표 삽입
            if (nx >= 0 && ny >= 0 && nz >= 0 && nx < H && ny < N && nz < M && box[nx][ny][nz] == 0) {
                //기존 좌표의 날짜에 +1 해서 삽입
                box[nx][ny][nz] = box[x][y][z] + 1;
                //가장 긴 일수인지 검사
                max = MAX(max, box[nx][ny][nz]);
                //큐에 새로운 좌표 삽입
                q.push({ nx,ny,nz });
            }
        }
        //검사가 끝난 큐는 pop
        q.pop();
    }
 
    //익지 않은 토마토가 있는지 검사
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (box[i][j][k] == 0) {
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }
    printf("%d\n", max > 0 ? max - 1 : 0);
    return 0;
}
