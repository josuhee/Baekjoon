//[백준] 1316 : 그룹 단어 체커

#include <stdio.h>
#include <string.h>
 
int main() {
    int N;
    scanf("%d", &N);
 
    char str[101];
    int alpha[26], cnt = 0;
    bool group;
 
    while (N--) {
        //alpha배열을 0으로 초기화
        memset(alpha, 0, sizeof(alpha));
        group = true;
 
        //단어입력받기
        scanf("%s", str);
        alpha[str[0] - 'a'] = 1;
 
        //그룹단어 검사
        for (int i = 1; i < strlen(str); i++) {
            if (alpha[str[i] - 'a'] == 0) alpha[str[i] - 'a'] = 1;
            else {
                if (str[i] == str[i - 1]) continue;
                else group = false;
            }
        }
 
        //그룹단어이면 +1
        if (group) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
