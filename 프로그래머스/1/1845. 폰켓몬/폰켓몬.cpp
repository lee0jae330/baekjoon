#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> nums)
{
    int sz = nums.size();
    set<int>s;
    for(int num: nums) {
        s.insert(num);
    }
    
    if(s.size() >= sz / 2) {
        return sz / 2;
    } else {
        return s.size();
    }
    
}