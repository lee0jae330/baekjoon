#include<bits/stdc++.h>

using namespace std;

int N;
vector<pair<int,int>>egg;
int broken;
int c;
void rec(int idx, int cnt){ //인덱스, 깬 갯수
    if(idx==N){
        broken=max(broken,cnt);
        return;
    }
    if(egg[idx].first<=0){
        rec(idx+1,cnt);
        return;
    }
    int tmp=0,f=1;
    for(int i=0;i<N;i++){ //1.가장왼쪽계란,2.계란을 들고 한번 치면 해당 계란을 내려 놓음
        if(i==idx)
            continue;
        if(egg[i].first>0){
            f=0;
            egg[idx].first -=egg[i].second;
            egg[i].first -=egg[idx].second;
            if(egg[idx].first<=0)
                tmp++;
            if(egg[i].first<=0)
                tmp++;
            rec(idx+1,cnt+tmp);
            egg[idx].first += egg[i].second;
            egg[i].first +=egg[idx].second;
            tmp=0;
        }
    }
    if(f)
        rec(idx+1,cnt);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i=0;i<N;i++){
        int s,w;
        cin >> s>>w;
        egg.push_back({s,w});
    }
    rec(0,0);
    cout << broken;
    return 0;
}