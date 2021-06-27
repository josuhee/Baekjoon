//[백준] 1978 : 소수 찾기

#include <stdio.h>
 
int main() {
    int N, num, cnt = 0;
    scanf("%d", &N);
 
    int i;
    while (N--) {
        scanf("%d", &num);
        //소수 검사
        for (i = 2; i < num; i++) {
            if (num%i == 0) break;
        }
        if (i == num) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}