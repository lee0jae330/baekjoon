#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin >> str;
    stack<char>s;
    int sol=0, sz= str.size();
    for(int i=0;i<sz;i++){
        if(str[i]=='('){
            s.push(str[i]);
        }
        else{
            s.pop();
            if(str[i-1]=='('){
                sol+=s.size(); 
            }
            else{
                sol++;
            }
            
        }
    }
    cout << sol <<'\n';
    return 0;
}