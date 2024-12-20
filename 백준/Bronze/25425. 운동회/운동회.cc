#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M, a, K;
    cin >> N >> M >> a >> K;
    long long num = a - K;
    long long mn, mx;
    if (num >= N) {
        mn = N;
    } else {
        mn = num + 1;
    }

    long long tmp = num / M;
    tmp += (num % M) ? 1 : 0;
    mx = tmp + 1;
    cout << mn << ' ' << mx << '\n';
    return 0;
}
