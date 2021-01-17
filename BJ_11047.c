//[백준] 11047 : 동전 0

#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int N, K;
    scanf("%d %d", &N, &K);
 
    //동전의 가치 입력
    int* coin = (int*)malloc(sizeof(int) * N);
    for (int i = N-1; i >= 0; i--)
        scanf("%d", &coin[i]);
 
    //동전의 최소 개수 구하기
    int cnt = 0, idx = 0;
    while (K > 0) {
        if (K >= coin[idx]) {
            K -= coin[idx];
            cnt++;
        }
        else idx++;
    }
 
    //결과 출력
    printf("%d\n", cnt);
    free(coin);
    return 0;
}
