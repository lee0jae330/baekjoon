#include<bits/stdc++.h>

using namespace std;

vector<int>v[27];
int visited[27];

int N, M;
int arr[27];

queue<int>q;
set<int>thief;

void bfs(int x) {
    q.push(x);
    visited[x] = 1;
    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (int i = 0; i < v[x].size(); i++) {
            int tx = v[x][i];
            if (!visited[tx] && thief.find(x)==thief.end() && thief.find(tx) == thief.end()) {
                q.push(tx);
                visited[tx] = 1;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        char a, b;
        cin >> a >> b;
        v[a - 'A'].push_back(b-'A');
        arr[b-'A'] =1; //자기 위에 누군가 있다는 뜻
    }

    int num ;
    cin >> num;
    while (num--) {
        char c;
        cin >> c;
        thief.insert(c-'A');
    }
    int root =0;
    for (int i = 0; i < N; i++) {
        if (!visited[i] && thief.find(i) == thief.end() && !arr[i]) {
            root++;
            bfs(i);
        }
    }
    /*for (int i = 0; i < N; i++) {
        cout << (char)('A'+i) <<": "<<visited[i] <<'\n';
    }
    */
    
    int sol =0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            sol++;
        }
    }
    cout << sol -root <<'\n';
    return 0;
}