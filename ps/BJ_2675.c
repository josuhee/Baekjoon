//[백준] 2675 : 문자열 반복

#include <stdio.h>
#include <string.h>
 
int main() {
    int T, R;
    char S[21];
    
    scanf("%d", &T);
    //T만큼의 테스트케이스
    while (T--) {
        scanf("%d %s", &R, S);
        
        //결과를 출력하기 위한 반복문
        for (int i = 0; i < strlen(S); i++) {
            for (int j = 0; j < R; j++)
                printf("%c", S[i]);
        }
 
        printf("\n");
    }
    return 0;
}
