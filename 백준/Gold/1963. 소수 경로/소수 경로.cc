#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int prime[10000];
int visited[10000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(prime, prime + 10000, 1);
    prime[1] = 0;
    for (int i = 2; i <= sqrt(9999); i++) {
        if (prime[i]) {
            for (int j = i * i; j <= 9999; j += i) {
                prime[j] = 0;
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        fill(visited, visited + 10000, -1);
        string a, b;
        int flag = 0;
        cin >> a >> b;
        visited[stoi(a)] = 0;
        queue<string> q;
        q.push(a);
        while (!q.empty()) {
            string x = q.front();

            q.pop();
            if (x == b) {
                cout << visited[stoi(x)] << '\n';
                flag = 1;
                break;
            }
            string tmp = x;
            for (int i = 0; i <= 3; i++) {
                for (int j = 0; j <= 9; j++) {
                    if (i == 0 && j == 0) continue;
                    tmp = x;
                    char c = '0' + j;
                    tmp[i] = c;
                    if (prime[stoi(tmp)] && visited[stoi(tmp)] == -1) {
                        visited[stoi(tmp)] = visited[stoi(x)] + 1;
                        q.push(tmp);
                    }
                }
            }
        }
        if (!flag) {
            cout << "Impossible" << '\n';
        }
    }
    return 0;
}