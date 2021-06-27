//[백준] 1365 : 꼬인 전깃줄

#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	int num;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);

		if (v.empty()) v.push_back(num);
		else {
			if (v.back() < num) v.push_back(num);
			else {
				auto it = lower_bound(v.begin(), v.end(), num);
				v[it - v.begin()] = num;
			}
		}
	}
	printf("%d\n", N - v.size());
	return 0;
}