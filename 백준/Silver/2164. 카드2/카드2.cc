#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>

using namespace std;

int main(void)
{
	queue<int>q;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		q.push(i + 1);
	while (q.size() > 1)
	{
		q.pop();
		q.push(q.front());
		q.pop();
	}
	printf("%d\n", q.front());
	return 0;
}