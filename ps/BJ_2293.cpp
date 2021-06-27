//[백준] 2293 : 동전 1

#include <stdio.h>
int dp[100001];
 
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
 
    //동전 배열 크기 동적 할당
    int* coin = new int[n];
 
    //동전의 가치 입력
    for (int i = 0; i < n; i++)
        scanf("%d", &coin[i]);
 
    //경우의 수 구하기
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= k; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }
 
    printf("%d\n", dp[k]);
    return 0;
}
