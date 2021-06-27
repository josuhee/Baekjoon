//[백준] 2839 : 설탕 배달

#include <stdio.h>
 
int main() {
    int N, cnt = 0;
    scanf("%d", &N);
    
    while (1) {
        if (N % 5 == 0) {
            cnt += N / 5;
            break;
        }
 
        N -= 3;
        cnt++;
        if (N <= 0) break;
    }
 
    if (N < 0) printf("-1\n");
    else printf("%d\n", cnt);
}