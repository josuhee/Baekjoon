//[백준] 1966 : 프린터 큐

#include <stdio.h>
#include <vector>
using namespace std;
 
int main() {
    int T;
    int n, m;
 
    //큐를 위한 벡터
    vector<pair<int,int>> v;
 
    //T개의 테스트케이스
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d %d", &n, &m);
        
        //각 문서에 우선순위 삽입
        int priority;
        for (int i = 0; i < n; i++) {
            scanf("%d", &priority);
            v.push_back(make_pair(priority, i));
        }
        
        //해당 문서가 몇 번째로 인쇄되는지 찾기
        int cnt = 1;
        while (1) {
 
            //큐가 비어있다면 cnt 출력하고 종료
            if (v.empty()) {
                printf("%d\n", cnt);
                break;
            }
 
            bool b = true;
            int size = v.size();
 
            //큐의 첫번째 요소의 우선순위가 제일 큰지 검사
            for (int i = 1; i < size; i++) {
                //우선순위가 크지 않다면
                //뒤로 넣기
                if (v[0].first < v[i].first) {
                    v.push_back(make_pair(v[0].first, v[0].second));
                    v.erase(v.begin());
                    b = false;
                    break;
                }
            }
 
            //첫 번째 요소가 제일 크다면
            if (b) {
                //찾고자 하는 문서라면
                //cnt 출력 및 종료
                if (v[0].second == m) {
                    printf("%d\n", cnt);
                    break;
                }
                //아니라면 첫 번째 요소 지우고
                //cnt++
                else {
                    v.erase(v.begin());
                    cnt++;
                }
            }
        }
        v.clear();
    }
 
    return 0;
}
