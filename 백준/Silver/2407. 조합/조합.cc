#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<algorithm>
#include<string.h>

using namespace std;

string dp[101][101] = {};

string add(string a, string b)
{
	int sum = 0;
	string result;
	while (!a.empty() || !b.empty() || sum)
	{
		if (!a.empty())
		{
			sum += a.back()-'0';
			a.pop_back();
		}
		if (!b.empty())
		{
			sum += b.back() - '0';
			b.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}

string comb(int n, int m)
{
	if (n == m || m == 0)
		return "1";
	if (dp[n][m] != "")
		return dp[n][m];
	dp[n][m] = add(comb(n-1,m-1), comb(n-1,m));
	return dp[n][m];
}

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	char tmp[101];
	strcpy(tmp, comb(N, M).c_str());
	printf("%s", tmp);
	return 0;
}

