#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
#include<string>

using namespace std;

vector<string>v;

bool cmp(string s1, string s2)
{
	string c1 = s1 + s2;
	string c2 = s2 + s1;
	return c1 > c2;
}

int main(void)
{
	int N;
	scanf("%d",&N);
	int tmp = 0;
	for (int i = 0; i < N; i++)
	{
		char num[11];
		scanf("%s", &num);
		string str(num);
		v.push_back(str);
		if (str[0] == '0')
			tmp++;
	}
	if (tmp == N)
	{
		printf("0\n");
		return 0;
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
	{
		const char* arr = v[i].c_str();
		printf("%s", arr);
	}
	printf("\n");
	return 0;
}