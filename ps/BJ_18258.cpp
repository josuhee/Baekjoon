//[백준] 18258 : 큐 2

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int main() {
	queue<int> q;
	int N, X;
	char str[10];
	scanf("%d", &N);
	
	while (N--) {
		scanf("%s", str);
		if (!strcmp(str, "push")) {
			scanf("%d", &X);
			q.push(X);
			continue;
		}
		else if (!strcmp(str,"pop")) {
			if (q.size() == 0) printf("-1\n");
			else {
				printf("%d\n", q.front());
				q.pop();
			}
			continue;
		}
		else if (!strcmp(str,"size")) {
			printf("%d\n", q.size());
			continue;
		}
		else if (!strcmp(str,"empty")) {
			printf("%d\n", q.empty());
			continue;
		}
		else if (!strcmp(str,"front")) {
			if (q.size() == 0) printf("-1\n");
			else printf("%d\n", q.front());
			continue;
		}
		else if (!strcmp(str,"back")) {
			if (q.size() == 0) printf("-1\n");
			else printf("%d\n", q.back());
			continue;
		}
	}

	return 0;
}