#include<bits/stdc++.h>

using namespace std;

int rec(int n, int r, int c){
    if(n==0) //base condition
        return 0;
    int half = 1<<n-1;
    if(r<half&&c<half) //1사분면
        return rec(n-1,r,c);
    else if(r<half&&c>=half)
        return half*half+rec(n-1,r,c-half);
    else if(r>=half&&c<half)
        return 2*half*half+rec(n-1,r-half,c);
    else
        return 3*half*half+rec(n-1,r-half,c-half);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , r, c;
    cin >> n >> r >> c;
    cout << rec(n,r,c);
    return 0;
}