//[백준] 1715 : 카드 정렬하기

#include <queue>
#include <iostream>
#include <functional>
using namespace std;

int main()
{
	int N, card;
	priority_queue<int, vector<int>, greater<int>> q;

	scanf("%d", &N);
	if (N == 1)
	{
		scanf("%d", &card);
		printf("0\n");
		return (0);
	}

	while (N--)
	{
		scanf("%d", &card);
		q.push(card);
	}

	int x, y, sum = 0;
	while (q.size() > 2)
	{
		x = q.top();
		q.pop();
		y = q.top();
		q.pop();

		sum += x + y;
		q.push(x + y);
	}
	x = q.top();
	q.pop();
	y = q.top();
	q.pop();
	sum += x + y;
	printf("%d\n", sum);
	return (0);
}