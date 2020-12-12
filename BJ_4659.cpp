//[백준] 4659 : 비밀번호 발음하기

#include <stdio.h>
#include <string.h>

int main() {
    int i, accept, vowel, consonants, exist;
    char pw[21];

    while (1) {
        vowel = consonants = exist = 0;
        accept = 1;
        scanf("%s", pw);
        //문자열이 "end"이면 프로그램 종료
        if (strcmp(pw, "end") == 0) break;
        //문자열 검사
        for (i = 0; i < strlen(pw); i++) {
            //모음일 때, 모음++, 자음=0
            //모음이 존재하므로 exist =1
            if (pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'u') {
                exist = 1;
                vowel++;
                consonants = 0;
            }
            //자음일 때, 자음++, 모음=0
            else {
                consonants++;
                vowel = 0;
            }
            //자음이나 모음의 개수가 3개일 때
            //accept를 0으로 바꾸고 검사 종료
            if (vowel == 3 || consonants == 3) {
                accept = 0;
                break;
            }
            //연속된 단어가 들어올 때,
            if (i < strlen(pw) - 1) {
                //ee나 oo는 통과
                if (pw[i] == 'e' && pw[i + 1] == 'e' || pw[i] == 'o' && pw[i + 1] == 'o') continue;
                //아니라면 accpet를 0으로 바꾸고 검사 종료
                else if (pw[i] == pw[i + 1]) {
                    accept = 0;
                    break;
                }
            }
        }
        //accept=1 이면서 exist=1 인 경우 acceptable, 그외 not acceptable
        if (accept && exist) printf("<%s> is acceptable.\n", pw);
        else printf("<%s> is not acceptable.\n", pw);
    }
    return 0;
}
