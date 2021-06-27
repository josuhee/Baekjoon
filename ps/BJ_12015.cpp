//[백준] 12015 : 가장 긴 증가하는 부분 수열 2

#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	int num;
	vector<int> v;
	while (N--) {
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
	printf("%d\n", v.size());
	return 0;
}