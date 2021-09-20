//[백준] 2751 : 수 정렬하기 2

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int N, num;
	vector<int> v;

	scanf("%d", &N);
	while(N--)
	{
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	for (int n : v)
		printf("%d\n", n);

	return (0);
}