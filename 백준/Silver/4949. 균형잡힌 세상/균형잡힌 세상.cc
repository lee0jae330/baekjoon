#include<iostream>
#include<string>
#include<stack>
using namespace std;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(void) {
    while (1) {
        string s1;
        getline(cin, s1);
        if (s1.size() == 1 && s1[0] == '.')
            break;
        stack<char>s;
        int flag = 0;
        for (int i = 0; i < s1.size(); i++) {
            char tmp = s1[i];
            if (tmp == '(' || tmp == '[') {
                s.push(tmp);
            }
            else if (tmp == ')' || tmp == ']') {
                char t;
                if (!s.empty()) {
                    t = s.top();
                    if (tmp == ')') {
                        if (t == '(') {
                            s.pop();
                        }
                        else {
                            flag = 1;
                        }
                    }
                    else if (tmp == ']') {
                        if (t == '[')
                            s.pop();
                        else {
                            flag = 1;
                        }
                    }
                }
                else {
                    flag = 1;
                }
            }
            if (flag)
                break;
        }
        if (s.empty()&&flag==0) {
            cout << "yes" << '\n';
        }
        else
            cout << "no" << '\n';
    }
   
    return 0;
}