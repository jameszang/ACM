#include <bits/stdc++.h>

#define nl '\n'
#define UPPER 1e5

enum decision {
    TAKE = 0,
    LEAVE = 1
};

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        m[temp]++;
    }
    
    //dp[i][j] where i == a_i and j == take or leave the number
    vector<vector<long long>> dp(UPPER+1, vector<long long>(2, 0));

    for (long long i = 1; i <= UPPER; i++) {
        if (m[i] > 0) {
            dp[i][TAKE] = dp[i-1][LEAVE] + (i * m[i]);
            dp[i][LEAVE] = max(dp[i-1][TAKE], dp[i-1][LEAVE]);
        } else {
            dp[i][TAKE] = max(dp[i-1][TAKE], dp[i-1][LEAVE]);
            dp[i][LEAVE] = max(dp[i-1][TAKE], dp[i-1][LEAVE]);
        }
    }

    cout << max(dp[UPPER][TAKE], dp[UPPER][LEAVE]) << nl;

    return 0;
}
