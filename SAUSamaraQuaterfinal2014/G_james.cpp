#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

int main() {
    long long coinCount = 0;
    long long n, s;
    cin >> n >> s;
    
    vector<long long> coin;
    coin.push_back(1);
    for (long long i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        if ((coin[i] * temp) > s) {
            break;
        } else {
            coin.push_back(coin[i] * temp);
        }
    }

    for (long long i = coin.size() - 1; i >= 0; i--) {
        if (coin[i] <= s) {
            coinCount += (s / coin[i]);
            s -= ((s / coin[i]) * coin[i]);
        }
    }
    cout << coinCount << nl;
    return 0;
}
