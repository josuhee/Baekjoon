//[백준] 1080 : 행렬

#include <stdio.h>
 
int arr[50][50];
 
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
 
    //행렬 A 입력받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            scanf("%1d", &arr[i][j]);
    }
 
    int num;
    //행렬 B 입력받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &num);
 
            //입력받은 값이 행렬 A와 다르다면 1
            if (arr[i][j] != num) arr[i][j] = 1;
            //같다면 0
            else arr[i][j] = 0;
        }
    }
 
    //전체 크기가 3*3이 되지 않는 경우
    if (N < 3 || M < 3) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j]) {
                    printf("-1\n");
                    return 0;
                }
            }
        }
        printf("0\n");
    }
    //전체 크기가 3*3보다 큰 경우
    else {
        int cnt = 0;
 
        //전체 범위 검사
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                //다른부분일 때,
                if (arr[i][j]) {
                    //3*3 범위내라면 뒤집기
                    if (i < N - 2 && j < M - 2) {
                        //3*3크기
                        for (int x = i; x < i + 3; x++) {
                            for (int y = j; y < j + 3; y++) {
                                arr[x][y] = !arr[x][y];
                            }
                        }
                        //횟수 count
                        cnt++;
                    }
                    //범위 밖이라면 더이상 뒤집을 수 없음
                    else {
                        if (arr[i][j]) {
                            printf("-1\n");
                            return 0;
                        }
                    }
                }
            }
        }
        //결과 출력
        printf("%d\n", cnt);
    }
    
 
    return 0;
}