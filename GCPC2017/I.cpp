#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

enum decision {
    TAKE = 0,
    LEAVE = 1
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> points(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> points[i];
    }

    //dp[i][j] where i = time slice and j = shoot ulti or not
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    for (int i = m+1; i <= n; i++) {
        dp[i][TAKE] = max(dp[i-m][LEAVE], dp[i-m][TAKE]) + points[i];
        dp[i][LEAVE] = max(dp[i-1][LEAVE], dp[i-1][TAKE]);
    }

    cout << max(dp[n][TAKE], dp[n][LEAVE]) << nl;

    return 0;
}
