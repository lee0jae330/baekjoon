#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int parent[100001];
int course[100001];

void init()
{
   for (int i = 0; i <= 100000; i++)
      parent[i] = i;
}

int find(int x)
{
   if (x == parent[x])
      return x;
   return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
   x = find(x);
   y = find(y);
   if (x != y)
   {
      if (x > y)
         parent[x] = y;
      else
         parent[y] = x;
   }
}

int main(void)
{
   init();
   int N, M;
   scanf("%d %d", &N, &M);
   for (int i = 0; i < M; i++)
   {
      int a, b;
      scanf("%d %d", &a, &b);
      merge(a, b);
   }
   for (int i = 1; i <= N; i++)
      scanf("%d", &course[i]);
   int cur = find(course[1]);
   int cnt = 0;
   for (int i = 2; i <= N; i++)
   {
      if (find(course[i]) != cur)
      {
         cnt++;
         cur = find(course[i]);
      }
   }

   printf("%d\n", cnt);
   return 0;
}