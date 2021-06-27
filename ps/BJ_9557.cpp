//[백준] 9557 : Arabic and English

#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100][11];
    int T, N;
    scanf("%d", &T);

    int i, alpha = -1;
    //T개의 테스트케이스
    while (T--) {
        alpha = -1;//소문자가 있는 인덱스 표시
        scanf("%d", &N);
        for (i = 0; i < N; i++) {
            scanf("%s", str[i]);

            //소문자라면 해당 인덱스 위치를 저장
            if (isalpha(str[i][0])) alpha = i;
        }
        //소문자가 없을 때,
        if (alpha == -1) {
            for (i = 0; i < N; i++) printf("%s ", str[i]);
            printf("\n");
        }
        else {//소문자가 존재할 때,
            for (i = alpha + 1; i < N; i++)
                printf("%s ", str[i]);
            printf("%s ", str[alpha]);
            for (i = 0; i < alpha; i++)
                printf("%s ", str[i]);
            printf("\n");
        }
    }
    return 0;
}