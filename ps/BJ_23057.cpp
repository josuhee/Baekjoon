//[백준] 23057 : 도전 숫자왕

#include <iostream>
#include <set>
using namespace std;

int main()
{
	int N, M, result;
	int card[21];
	set<int> s;

	//init & input
	M = result = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &card[i]);
		M += card[i];
	}

	//brute force & bit mask
	int select = 1, sum;
	while (1)
	{
		if (select == (1 << N)) break ;
		sum = 0;
		for (int idx = 0; idx < N; idx++)
		{
			if (select & (1 << idx))
				sum += card[idx];
		}
		s.insert(sum);
		select++;
	}

	//result & output
	result = M - s.size();
	printf("%d\n", result);
	return (0);
}