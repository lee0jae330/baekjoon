#include<bits/stdc++.h>

using namespace std;

int arr[21];
bool isused[21];
int cnt, N,S;

void rec(int num, int sum){
    if(num==N){
        if(sum==S)
            cnt++;
        return;
    }
    rec(num+1,sum);//안더하는 경우
    rec(num+1,sum+arr[num]);//더하는 경우
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >>S;
    for(int i=0;i<N;i++)
        cin >> arr[i];
    rec(0,0);
    if(!S)
        cnt--;
    cout << cnt <<'\n';
    return 0;
}