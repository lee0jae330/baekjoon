#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<memory.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

int parent[10001];
const double ZERO = 0.000001;

void init()
{
    for (int i = 0; i <= 10000; i++)
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

int isIntersect(pair<pair<long long, long long>, pair<long long, long long>>x, pair<pair<long long, long long>, pair<long long, long long>>y)
{
    pair<long long, long long>a = x.first;
    pair<long long, long long>b = x.second;
    pair<long long, long long>c = y.first;
    pair<long long, long long>d = y.second;
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return c <= b && a <= d;
}

pair<pair<double, double>, pair<double, double>> line[10001];
double grad[10001];
int sol[10001];

int main(void)
{
    init();
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        double a, b, c, d;
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        line[i].first.first = a, line[i].first.second = b, line[i].second.first = c, line[i].second.second = d;
        if (fabs(c - a) <= ZERO)
            grad[i] = 1000000.0;
        else if (fabs(d - b) <= ZERO)
            grad[i] = 0.000000;
        else
        {
            grad[i] = (d - b) / (c - a) ;
        }
    }
    double g1 = 0.000000;
    double g2 = 1000000.000000;
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            if (fabs(grad[i]-grad[j]) <= ZERO)
            {
                pair<double,double>a = line[i].first;
                pair<double, double>b = line[i].second;
                pair<double, double>c = line[j].first;
                pair<double, double>d = line[j].second;
                if (a > b)
                    swap(a, b);
                if (c > d)
                    swap(c, d);
                if (fabs(grad[i]-g1) <=ZERO)
                {
                    if (line[i].first.second == line[j].first.second && c <= b && a <= d)
                        merge(i, j);
                    continue;
                }
                else if (fabs(grad[i]-g2)<=ZERO)
                {
                    if (line[i].first.first == line[j].first.first && c <= b && a <= d)
                        merge(i, j);
                    continue;
                }
                double xx1 = -grad[i] * a.first + a.second;
                double xx2 = -grad[j] * c.first + c.second;
                double yy1 = grad[i] * a.first - a.second;
                double yy2 = grad[j] * c.first - c.second;
                if (fabs(xx1-xx2) <= ZERO && fabs(yy1-yy2) <= ZERO)
                {
                    if (c <= b && a <= d)
                        merge(i, j);
                }
            }
        }
    }
    int tmp = N;
    for (int i = 1; i <= N; i++)
    {
        if (!sol[find(i)])
        {
            for (int j = i + 1; j <= N; j++)
            {
                if (find(i) == find(j))
                {
                    tmp--;
                    sol[find(i)] = 1;
                }
            }
           
        }
    }

    printf("%d\n", tmp);
    return 0;
}