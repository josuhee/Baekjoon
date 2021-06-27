//[백준] 9095 : 1, 2, 3 더하기

#include <stdio.h>
 
int main() {
    int dp[11] = { 0 };
    //초깃값
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
 
    //각 숫자마다 방법의 수 구하기
    for (int i = 4; i < 11; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
 
    int T, n;
    scanf("%d", &T);
 
    //결과 출력
    for (int test_case = 0; test_case < T; test_case++) {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
 
    return 0;
}
