//[백준] 10845 : 큐

#include <queue>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	int n;
	char str[10];
	queue<int> q;

	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", str);

		if (!strcmp(str, "push"))
		{
			int num;

			scanf("%d", &num);
			q.push(num);
		}
		if (!strcmp(str, "pop"))
		{
			if (q.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", q.front());
				q.pop();
			}
		}
		if (!strcmp(str, "size"))
			printf("%d\n", q.size());
		if (!strcmp(str, "empty"))
		{
			if (q.empty())
				printf("1\n");
			else
				printf("0\n");
		}
		if (!strcmp(str, "front"))
		{
			if (q.empty())
				printf("-1\n");
			else
				printf("%d\n", q.front());
		}
		if (!strcmp(str, "back"))
		{
			if (q.empty())
				printf("-1\n");
			else
				printf("%d\n", q.back());
		}
	}
	return (0);
}