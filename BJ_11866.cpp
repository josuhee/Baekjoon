//[백준] 11866 : 요세푸스 문제 0

#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++)
		v.push_back(i);

	int idx = K - 1;
	printf("<");
	while (1) {
		if (v.size() == 1) {
			printf("%d>\n", v[idx]);
			break;
		}
		else printf("%d, ", v[idx]);
		v.erase(v.begin() + idx);

		idx--;
		idx = (idx + K) % v.size();
	}

	return 0;
}