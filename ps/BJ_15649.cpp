//[백준] 15649 : N과 M (1)

#include <stdio.h>
 
int N, M;
int arr[8];
bool visit[8];
 
void func(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
 
    for (int i = 1; i <= N; i++) {
        if (!visit[i]) {
            visit[i] = true;
            arr[cnt] = i;
            func(cnt + 1);
            visit[i] = false;
        }
    }
}
 
int main() {    
    scanf("%d %d", &N, &M);
    func(0);
    return 0;
    
}