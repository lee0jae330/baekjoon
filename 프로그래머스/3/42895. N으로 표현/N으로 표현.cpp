#include<bits/stdc++.h>

using namespace std;

unordered_set<int>s[9];

int solution(int N, int number) {
    string n = to_string(N);
    
    for(int i =1 ;i<=8;i++) {
        string str="";
        for(int j = 1; j<=i;j++) {
            str+=n;
        }
        s[i].insert(stoi(str));
    }
    
    for(int i = 2; i<=8;i++) {
        for(int j = 1;j<i;j++) {
            int l = j, r = i - j;
            for(auto x : s[l]) {
                for(auto y: s[r]) {
                    if(x+y <32001) {
                        s[i].insert(x+y);
                    }
                    if(x-y>0) {
                        s[i].insert(x-y);
                    }
                    if(y-x>0) {
                        s[i].insert(y-x);
                    }
                    if(x*y<32001) {
                        s[i].insert(x*y);
                    }
                    if(x/y>0) {
                        s[i].insert(x/y);
                    }
                    if(y/x>0) {
                        s[i].insert(y/x);
                    }
                }
            }
        }
    }
    for(int i = 1;i<=8;i++) {
        for(int num : s[i]) {
            if(num == number) {
                return i;
            }
        }
    }
    return -1;    
}