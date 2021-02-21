//[백준] 1759 : 암호만들기

#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
 
char alpha[16];
int visit[16];
int L, C;
 
//암호 구성 체크
void check() {
    char str[16];
    int vowel = 0, idx = 0;
 
    //문자열 검사
    for (int i = 0; i < C; i++) {
        if (visit[i]) {
            str[idx] = alpha[i];
            idx++;
            if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u') 
                vowel++;
        }
    }
    str[L] = '\0';
    
    //모음이 1개 이상이면서 자음이 2개 이상인 문자열이라면 출력
    if (vowel && L - vowel >= 2) printf("%s\n", str);
}
 
//브루트포스
int select(int idx, int cnt) {
    //길이가 L이라면 선택한 문자 검사
    if (cnt == L) {
        check();
        return 0;
    }
 
    if (idx == C) return 0;
 
    //해당 좌표를 방문했을 때
    visit[idx] = 1;
    select(idx + 1, cnt + 1);
 
    //해당 좌표를 방문하지 않는다면
    visit[idx] = 0;
    select(idx + 1, cnt);
 
    return 0;
}
 
int main() {
    
    scanf("%d %d", &L, &C);
 
    for (int i = 0; i < C; i++)
        scanf(" %c", &alpha[i]);
    
    //알파벳 정렬
    sort(alpha, alpha + C);
 
    //오름차순으로 검사
    for (int i = 0; i <= C - L; i++) {
        memset(visit, 0, sizeof(visit));
        visit[i] = 1;
        select(i + 1, 1);
    }
 
    return 0;
}
