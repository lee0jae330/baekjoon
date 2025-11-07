#include<bits/stdc++.h>

using namespace std;



vector<int> solution(vector<string> operations) {
    multiset<int>ms;
    for(string str: operations) {
        char cmd = str[0];
        string tmp = str.substr(2);
        int num = stoi(tmp);
        
        if(cmd =='I') {
            ms.insert(num);
        } else {
            if(ms.empty()) {
                continue;
            }
            
            if(num == 1) {
                ms.erase(--ms.end());
            } else {
                ms.erase(ms.begin());
            }
        }
    }
    vector<int>v(2,0);
    if(ms.empty()) {
        return v;
    }
    auto end = ms.end();
    end--;
    v[0] = *end;
    v[1] = *ms.begin();
    return v;
    
}