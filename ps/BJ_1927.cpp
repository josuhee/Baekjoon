//[백준] 1927 : 최소 힙

#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue<int, vector<int>, greater<int>> q;

	int N, query;
	cin >> N;

	while (N--) {
		cin >> query;
		if (query) {
			q.push(query);
		}
		else {
			if (q.empty()) cout << "0\n";
			else {
				cout << q.top() << "\n";
				q.pop();
			}
		}
	}

	return 0;
}