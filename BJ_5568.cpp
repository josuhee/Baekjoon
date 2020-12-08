//[백준] 5568 : 카드 놓기

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
using namespace std;

char card[10][10];
char choice[4][10];
bool visit[10];
int n, k;
set<int> s;

int dfs(int cnt) {
    //k개를 선택했으면 문자열을 set에 저장
    if (cnt == k) {
        char str[20] = "\0";
        for (int i = 0; i < k; i++)
            strcat(str, choice[i]);
        s.insert(atoi(str));
    }

    //k개 선택하는 방법
    for (int i = 0; i < n; i++) {
        //방문하지 않은 곳이면
        if (!visit[i]) {
            visit[i] = true;//방문
            //문자열 이어 붙이기
            strcpy(choice[cnt], card[i]);
            //1추가해서 다음 dfs 돌리기
            dfs(cnt + 1);
            //dfs 탈출하면 방문기록을 false로
            visit[i] = false;
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%s", card[i]);
    }
    dfs(0);
    printf("%d\n", s.size());
    return 0;
}