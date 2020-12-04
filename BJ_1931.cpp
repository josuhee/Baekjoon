//[����] 1931 : ȸ�ǽ� ����

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

//������ �ð��� �������� ����
//������ �ð��� ���ٸ� ���۽ð��� ���� ������ ����
bool compare(pair<int, int>a, pair<int, int>b) {
    if (a.second == b.second)
        return a.first < b.first;
    else return a.second < b.second;
}

int main() {
    int N;
    scanf("%d", &N);

    //ȸ�� ����,���� �ð� �ֱ�
    vector<pair<int, int>> v;
    int start, end;
    while (N--) {
        scanf("%d %d", &start, &end);
        v.push_back(make_pair(start, end));
    }

    //����
    sort(v.begin(), v.end(), compare);

    //�ִ� ȸ�� ���� ���ϱ�
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
