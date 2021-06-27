//[백준] 6378 : 디지털 루트

#include <stdio.h>
#include <string.h>

int main() {
    char N[1001];
    int root;
    while (1) {
        root = 0;
        scanf("%s", N);
        if (strcmp(N, "0") == 0) break;
        //입력받은 숫자의 각 자리수를 모두 더함
        for (int i = 0; i < strlen(N); i++) {
            root += N[i] - '0';
        }
        //디지털 루트 구하기
        while (root >= 10) {
            root = root / 10 + root % 10;
        }
        printf("%d\n", root);
    }
    return 0;
}
