#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

int main() {
    int coinCount = 0;
    int n, s;
    cin >> n >> s;
    
    vector<int> coin(n, 0);
    int tempValue = 1;
    int breakIndex = n - 1;
    for (int i = 0; i < n; i++) {
        int tempCin;
        cin >> tempCin; 
        tempValue *= tempCin;
        if (tempValue > s ) {
            breakIndex = i - 1;
            break;
        }
        coin[i] = tempValue;
    }

    for (int i = breakIndex; i >= 0; i--) {
        if (coin[i] <= s) {
            coinCount += (s / coin[i]);
            s %= coin[i];
        }
    }
    coinCount += s;
    cout << coinCount << nl;
    return 0;
}
