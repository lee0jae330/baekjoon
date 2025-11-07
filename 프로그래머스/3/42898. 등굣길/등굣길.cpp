#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int arr[101][101];
ll dp[101][101];

const int MOD = 1e9+7;


int solution(int m, int n, vector<vector<int>> puddles) {
    for(auto v: puddles) {
        int x = v[0], y=v[1];
        x--, y--;
        arr[y][x] = 1;
    }
    dp[0][0] =1;
    for(int i =0 ;i<m;i++) {
        if(arr[0][i]) {
            break;
        }
        dp[0][i] = 1;
    }
    for(int i =0 ;i<n;i++) {
        if(arr[i][0]) {
            break;
        }
        dp[i][0] = 1;
    }
    
    for(int i = 1; i<n;i++) {
        for(int j = 1; j<m;j++) {
            if(arr[i][j]) {
                continue;
            }
            dp[i][j] = ((dp[i-1][j] %MOD) + (dp[i][j-1]%MOD) %MOD);
        }
    }

    return dp[n-1][m-1] % MOD;
}