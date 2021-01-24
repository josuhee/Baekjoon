//[백준] 2875 : 대회 or 인턴

#include <stdio.h>
 
int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
 
    //최대 몫 구하기
    int max = N / 2 < M ? N / 2 : M;
    
    //전체에서 최대값을 제외한 나머지 값을
    //K에 빼준다.
    K -= N + M - 3 * max;
 
    //K가 0보다 크다면
    //3으로 나눈 몫만큼 max에서 빼준다.
    if (K > 0) {
        K--;
        max -= K / 3 + 1;
    }
 
    printf("%d\n", max);
    return 0;
}
