//[백준] 1655 : 가운데를 말해요

#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, num;
	cin >> N;
	priority_queue<int> pq1;
	priority_queue<int, vector<int>, greater<int>> pq2;

	for (int test_case = 1; test_case <= N; test_case++) {
		cin >> num;
		if (test_case==1) pq1.push(num);
		else if (test_case == 2) {
			int tmp = pq1.top();
			if (num > tmp) pq2.push(num);
			else {
				pq2.push(tmp);
				pq1.pop();
				pq1.push(num);
			}
		}
		else {
			if (test_case % 2) {
				pq1.push(num);
			}
			else {
				pq2.push(num);
			}

			if (pq1.top() > pq2.top()) {
				int tmp1 = pq1.top(), tmp2 = pq2.top();
				pq1.pop(); pq2.pop();
				pq1.push(tmp2); pq2.push(tmp1);
			}
		}
		
		cout << pq1.top() << "\n";
	}
	return 0;
}