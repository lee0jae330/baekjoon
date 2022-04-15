#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<set>
#include<algorithm>

using namespace std;

int main(void)
{
	char tmp;
	int T, N, A;
	scanf("%d", &T);
	getchar();
	for (int i = 0; i < T; i++)
	{
		multiset<int>mt;
		scanf("%d", &N);
		getchar();
		for (int j = 0; j < N; j++)
		{
			scanf("%c %d", &tmp, &A);
			getchar();
			if (tmp == 'I')
			{
				mt.insert(A);
			}
			else
			{
				if (mt.empty())
					continue;
				else
				{
					if (A == -1)
						mt.erase(mt.begin());
					else
						mt.erase(--mt.end());
				}
			}
		}
		if (mt.empty())
			printf("EMPTY\n");
		else
		{
			auto end = mt.end();
			end--;
			printf("%d %d\n", *end, *mt.begin());
		}
	}
	return 0;
}