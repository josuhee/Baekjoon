// [백준] 2512 : 예산

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, total = 0, money;
	vector<int> v;

	// input
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &money);
		total += money;
		v.push_back(money);
	}
	scanf("%d", &m);

	// sort
	sort(v.begin(), v.end());

	// solution
	if (total < m)
		printf("%d\n", v[n - 1]);
	else
	{
		int left = 0;
		int right = v[n - 1];
		int result;

		// binary search
		while (left <= right)
		{
			int mid = (left + right) / 2;
			int idx = lower_bound(v.begin(), v.end(), mid) - v.begin();
			
			// budget calculation
			int sum = 0;
			for (int i = 0; i < idx; i++)
				sum += v[i];
			sum += (mid * (n - idx));

			// binary search role
			if (sum > m)
				right = mid - 1;
			else
			{
				left = mid + 1;
				result = mid;
			}
		}

		// result
		printf("%d\n", result);
	}
	return (0);
}