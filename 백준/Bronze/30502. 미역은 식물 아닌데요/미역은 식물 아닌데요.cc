#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

set<int> P[1001];
set<int> M[1001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, c;
        char b;
        cin >> a >> b >> c;
        if (b == 'P') {
            P[a].insert(c);
        } else {
            M[a].insert(c);
        }
    }
    int mn = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
        if (P[i].size() == 1 && P[i].find(1) != P[i].end() && M[i].size() == 1 &&
            M[i].find(0) != M[i].end()) {
            mn++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (P[i].size() == 0) {
            if (M[i].size() == 0 || M[i].find(0) != M[i].end()) {
                mx++;
            }
        } else {
            if (P[i].find(1) != P[i].end() && (M[i].size() == 0 || M[i].find(0) != M[i].end())) {
                mx++;
            }
        }
    }
    cout << mn << ' ' << mx << '\n';
    return 0;
}