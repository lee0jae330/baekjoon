#include<bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string,int>m;
    
    for(string str: completion) {
        if(m.find(str) == m.end()) {
            m[str] = 1;
        } else {
            m[str]++;
        }
    }
    
    for(string str : participant) {
        if(m.find(str) == m.end() || m[str] == 0) {
            return str;
        } else {
            m[str]--;
        }
    }
}