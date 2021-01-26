//[백준] 14881 : 물통 문제

#include <stdio.h>
 
int main() {
    int T, a, b, c;
    scanf("%d", &T);
 
    for (int i = 0; i < T; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (c > a && c > b) printf("NO\n");
        else {
            //a물통이 무조건 b보다 크도록 만든다.
            if (a < b) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            int r;
            //최대공약수구하기
            while (b != 0) {
                r = a % b;
                a = b;
                b = r;
            }
 
            //결과출력
            if (a == 1 || c % a == 0) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
