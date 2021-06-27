//[백준] 11403 : 경로 찾기

#include <stdio.h>
#define INF 987654321
#define MIN(a,b) a<b?a:b
int arr[100][100];
 
int main() {
    int N;
    scanf("%d", &N);
 
    //인접행렬 입력받기
    //간선이 없다면 가장 큰 수를 삽입
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 0) arr[i][j] = INF;
        }
    }

    //플로이드 알고리즘
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                arr[i][j] = MIN(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
 
    //결과 출력
    //결과가 가장 큰 수라면 경로가 없다는 뜻이므로 0
    //그 외에는 1
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == INF) printf("0 ");
            else printf("1 ");
        }
        printf("\n");
    }
 
 
    return 0;
}
