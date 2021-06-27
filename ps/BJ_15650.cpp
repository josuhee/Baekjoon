//[백준] 15650 : N과 M (2)

#include <stdio.h>
#include <string.h>

int N, M;
bool visit[9];

int func(int idx, int cnt) {
    if (cnt == M) {
        for (int i = 1; i <= N; i++) {
            if (visit[i]) printf("%d ", i);
        }
        printf("\n");
        return 0;
    }

    if (idx == N + 1) return 0;

    visit[idx] = true;
    func(idx + 1, cnt + 1);
    visit[idx] = false;
    func(idx + 1, cnt);
    return 0;
}

int main() {
    scanf("%d %d", &N, &M);
    
    for (int i = 1; i <= N - M + 1; i++) {
        memset(visit, 0, sizeof(visit));
        visit[i] = true;
        func(i + 1, 1);
    }

    return 0;
}