//[백준] 16926 : 배열 돌리기 1

#include <stdio.h>
 
int arr[300][300];
 
void rotate(int n, int m, int r, int idx) {
    int i, j, x, y;
    //r만큼 한칸씩 옮기기
    while (r--) {
        j = idx;
        x = n - 2+idx, y = idx;
        int tmp = arr[idx+n - 1][idx];
 
        //왼쪽 부분
        for (i = idx+n - 1; i > idx; i--) {
            arr[i][j] = arr[x][y];
            x--;
        }
 
        //윗 부분
        x = idx; y = idx + 1;
        for (j = idx; j < m-1+idx; j++) {
            arr[i][j] = arr[x][y];
            y++;
        }
 
        //오른쪽 부분
        x = 1+idx; y = m - 1 + idx;
        for (i = idx; i < n - 1+idx; i++) {
            arr[i][j] = arr[x][y];
            x++;
        }
 
        //아랫 부분
        x = n - 1+idx; y = m - 2+idx;
        for (j = m - 1+idx; j > 1+idx; j--) {
            arr[i][j] = arr[x][y];
            y--;
        }
        arr[i][j] = tmp;
    }
 
}
 
int main() {
    int N, M, R;
    scanf("%d %d %d", &N, &M, &R);
 
    //배열 입력받기
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &arr[i][j]);
 
    int idx = 0, n = N, m = M;
    while (1) {
        //회전 수를 한바퀴 기준으로 모드 연산
        int r = R % (2 * n + 2 * m - 4);
        rotate(n, m, R, idx);
        idx++;
        n -= 2;
        m -= 2;
        if (n == 0 || m == 0) break;
    }
 
    //결과 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
 
    return 0;
}
