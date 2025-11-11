#include<bits/stdc++.h>

using namespace std;

int L,C;
vector<char>str;
vector<char>sol;
int isused[16];

void rec(int K,int idx,int son, int mom){
    if(K==L){
        if(mom>=1&&son>=2){
            for(auto a:sol)
                cout << a;
            cout <<'\n';
            return;
        }
    }
    for(int i=idx;i<C;i++){
        if(!isused[i]){
            sol.push_back(str[i]);
            isused[i]=1;
            if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
                rec(K+1,i+1,son,mom+1);
            else
                rec(K+1,i+1,son+1,mom);
            isused[i]=0;
            sol.pop_back();
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> L >> C;
    for(int i=0;i<C;i++){
        char ch; cin >> ch;
        str.push_back(ch);
    }
    sort(str.begin(),str.end());
    rec(0,0,0,0);
    return 0;
}