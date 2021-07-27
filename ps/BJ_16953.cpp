//[백준] 16953 : A → B

#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
	long a, b;

	scanf("%ld %ld", &a, &b);
	if (b % 10 != 1 && b % 10 % 2 == 1)
	{
		printf("-1\n");
		return (0);
	}
	queue<pair<long, int>> q;
	q.push({a, 1});
	while (!q.empty())
	{
		long num = q.front().first;
		int cnt = q.front().second;
		q.pop();

		long first = num * 2;
		long second = num * 10 + 1;
		if (first == b || second == b)
		{
			printf("%d\n", cnt + 1);
			return (0);
		}
		if (first < b)
			q.push({first, cnt + 1});
		if (second < b)
			q.push({second, cnt + 1});
	}
	printf("-1\n");
	return (0);
}