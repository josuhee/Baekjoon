//[백준] 1931 : 회의실 배정

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

//끝나는 시간을 기준으로 정렬
//끝나는 시간이 같다면 시작시간이 빠른 순서로 정렬
bool compare(pair<int, int>a, pair<int, int>b) {
    if (a.second == b.second)
        return a.first < b.first;
    else return a.second < b.second;
}

int main() {
    int N;
    scanf("%d", &N);

    //회의 시작,종료 시간 넣기
    vector<pair<int, int>> v;
    int start, end;
    while (N--) {
        scanf("%d %d", &start, &end);
        v.push_back(make_pair(start, end));
    }

    //정렬
    sort(v.begin(), v.end(), compare);

    //최대 회의 개수 구하기
    int cnt = 1;
    end = v[0].second;
    for (int i = 1; i < v.size(); i++) {
        if (v[i].first >= end) {
            end = v[i].second;
            cnt++;
        }
    }

    printf("%d\n", cnt);

    return 0;
}
