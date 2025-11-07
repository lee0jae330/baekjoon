#include<bits/stdc++.h>

using namespace std;

int arr[501][501];
int dp[501][501];

int solution(vector<vector<int>> triangle) {
    for(int i = 0 ;i<501;i++) {
        fill(arr[i], arr[i]+501, -1);
    }
    
    int sz = triangle.size();
    
    for(int i =0 ;i<triangle.size();i++) {
        for(int j =0;j<triangle[i].size();j++) {
            arr[i][j] = triangle[i][j];
        }
    }
    dp[0][0] = arr[0][0];
    
    for(int i =1 ;i<sz ;i++) {
        for(int j = 0;j<triangle[i].size();j++) {
            int tmp = dp[i-1][j];
            if(j-1 >=0) {
                tmp = max(tmp, dp[i-1][j-1]);
            }
            dp[i][j] += tmp + arr[i][j];
        }
    }
    
    int sol = 0;
    for(int i = 0;i<501;i++) {
        sol = max(sol, dp[sz-1][i]);
    }
    
    return sol;
}