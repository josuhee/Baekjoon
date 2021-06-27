//[백준] 1697 : 숨바꼭질

#include <stdio.h>
#include <queue>
#define SIZE 100000
using namespace std;
 
bool visit[SIZE + 1];
 
int main() {
    int N, K;
    scanf("%d %d", &N, &K);
 
    queue<pair<int, int>> q;
    q.push(make_pair(0, N));
    visit[N] = true;
 
    int result = 0;
    while (1) {
        int cnt = q.front().first;
        int place = q.front().second;
 
        //위치를 찾았다면 break
        if (place == K) {
            result = cnt;
            break;
        }
 
        //세가지의 경우를 조건에 맞춰 push
        if (place - 1 >= 0 && !visit[place - 1]) {
            q.push(make_pair(cnt + 1, place - 1));
            visit[place - 1] = true;
        }
        if (place + 1 <= SIZE && !visit[place + 1]) {
            q.push(make_pair(cnt + 1, place + 1));
            visit[place + 1] = true;
        }
        if (place * 2 <= SIZE && !visit[place * 2]) {
            q.push(make_pair(cnt + 1, place * 2));
            visit[place * 2] = true;
        }
 
        //사용한 큐는 pop
        q.pop();
    }
    printf("%d\n", result);
    return 0;
}
