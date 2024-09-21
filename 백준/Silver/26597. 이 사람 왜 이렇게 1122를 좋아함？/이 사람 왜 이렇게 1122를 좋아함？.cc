#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long mn = -1e18, mx = 1e18;
    int Q, turn = 1;
    int sol = 999999, paradox = 999999;
    cin >> Q;
    while (Q--) {
        long long num;
        char c;
        cin >> num >> c;
        if (c == '^') {
            mn = max(num + 1, mn);
        } else {
            mx = min(num - 1, mx);
        }
        if (mn == mx) {
            sol = min(sol, turn);
        }
        if (mx < mn) {
            paradox = min(paradox, turn);
        }
        turn++;
    }
    if (paradox != 999999) {
        cout << "Paradox!" << '\n' << paradox << '\n';
        return 0;
    }
    if (sol != 999999) {
        cout << "I got it!" << '\n' << sol << '\n';
        return 0;
    }
    cout << "Hmm...";
    return 0;
}