//[백준] 2579 : 계단 오르기

#include <stdio.h>
#define MAX(a,b) a>b?a:b
 
int dp[301];
int stair[301];
 
int main() {
    int N;
    scanf("%d", &N);
 
    for (int i = 1; i <= N; i++) {
        scanf("%d", &stair[i]);
    }
 
    //초기값 지정해주기
    dp[0] = 0;
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
 
    //최대 값 구하기
    for (int i = 3; i <= N; i++) {
        dp[i] = stair[i] + (MAX(dp[i - 2], stair[i - 1] + dp[i - 3]));
    }
 
    //결과 출력
    printf("%d\n", dp[N]);
    return 0;
}
