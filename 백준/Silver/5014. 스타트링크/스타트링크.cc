#include<bits/stdc++.h>

using namespace std;

int visited[1000001];
int F,S,G,U,D;

void bfs(int x){
    queue<int>q;
    q.push(x);
    visited[x]=0;
    while(!q.empty()){
        x=q.front();
        q.pop();
        for(auto i : {x+U,x-D}){
            if(i<1||i>F)
                continue;
            if(visited[i]==-1){
                visited[i]=visited[x]+1;
                q.push(i);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> F >> S >> G >> U >> D;
    for(int i=0;i<=F;i++){
        visited[i]=-1;
    }
    bfs(S);
    if(visited[G]==-1)
        cout << "use the stairs";
    else
        cout << visited[G];
    return 0;
}