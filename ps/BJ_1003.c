//[백준] 1003 : 피보나치 함수

#include <stdio.h>

int main() {
    int T, N, fibo[41][2];
    scanf("%d", &T);

    //0번째, 0의 개수 = 1, 1의 개수 = 0
    fibo[0][0] = 1; fibo[0][1] = 0;

    //1번째, 0의 개수 = 0, 1의 개수 = 1
    fibo[1][0] = 0; fibo[1][1] = 1;

    //0과 1의 개수를 구하는 피보나치 수열
    for (int i = 2; i <= 40; i++) {
        fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
        fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
    }

    //T개의 테스트 케이스
    while (T--) {
        scanf("%d", &N);
        printf("%d %d\n", fibo[N][0], fibo[N][1]);
    }
    return 0;
}