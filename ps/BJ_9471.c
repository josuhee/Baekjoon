//[백준] 9471 : 피사노 주기

#include <stdio.h>
 
int main() {
    int P, N, M;
    scanf("%d", &P);
 
    int cnt, a, b;
    for (int i = 0; i < P; i++) {
        scanf("%d %d", &N, &M);
        cnt = 0;
        a = b = 1;
        while (1) {
            int tmp = (a + b) % M;
            a = b;
            b = tmp;
            cnt++;
 
            //주기를 찾으면 break
            if (a==1 && b == 1) break;
        }
        printf("%d %d\n", N, cnt);
    }
    return 0;
}