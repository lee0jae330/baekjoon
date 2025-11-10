#include<bits/stdc++.h>

using namespace std;

int N,M;
vector<int>v;
int arr[10];
bool isused[10];

void rec(int K,int num){
    if(K==M){
        for(int i=0;i<M;i++)
            cout << arr[i]<<' ';
        cout <<'\n';
        return;
    }
    for(int i=num;i<N;i++){
            arr[K]=v[i];
            rec(K+1,i);
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    rec(0,0);
    return 0;
}