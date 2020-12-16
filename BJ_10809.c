//[백준] 10809 : 알파벳 찾기

#include <stdio.h>
#include <string.h>

int main() {
    char word[101];
    int alpha[26];
    scanf("%s", word);

    int i, idx;
    //alpha 초기화
    for (i = 0; i < 26; i++) {
        alpha[i] = 100;
    }

    //각 알파벳이 처음 등장하는 위치 탐색
    for (i = 0; i < strlen(word); i++) {
        idx = word[i] - 'a';
        if (alpha[idx] > i)
            alpha[idx] = i;
    }

    //출력
    for (i = 0; i < 26; i++) {
        if (alpha[i] == 100) printf("-1 ");
        else printf("%d ", alpha[i]);
    }
    printf("\n");

    return 0;
}
