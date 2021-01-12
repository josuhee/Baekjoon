//[백준] 2346 : 풍선 터뜨리기

#include <vector>
#include <iostream>
using namespace std;
 
int main() {
    vector<pair<int, int>> v;
    int N, tmp;
    scanf("%d", &N);
 
    //풍선의 번호와 종이의 숫자 입력
    for (int i = 1; i <= N; i++) {
        scanf("%d", &tmp);
        v.push_back({ i, tmp });
    }
 
    //풍선 터뜨리기
    int idx = 0;
    while (1) {
        //터뜨릴 풍선의 번호를 출력
        printf("%d ", v[idx].first);
 
        //풍선에 있던 종이의 숫자 저장
        int n = v[idx].second;
 
        //풍선 터뜨리기(지우기)
        v.erase(v.begin() + idx);
        
        //남은 풍선이 없다면 break
        if (v.empty()) break;
        
        //종이의 숫자가 양수라면
        if (n > 0) {
            n--;
            idx += n;
            idx = idx % v.size();
        }
        //음수일 때,
        else {
            idx += n;
            if (idx < 0) {
                idx *= -1;
                idx = (v.size() - idx % v.size()) % v.size();
            }
        }
    }
    printf("\n");
    return 0;
}