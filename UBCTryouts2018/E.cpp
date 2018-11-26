#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

enum option {
    TAKE = 0,
    LEAVE = 1
};

int main() {
    int N;
    cin >> N;

    vector<int> data(N+1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> data[i];
    }

    int ans = 0;
    // do dp starting at each of N different positions
    for (int i = 0; i < N; i++) {
        vector<vector<int>> dp(2, vector<int>(N+1, 0));
        for (int k = 1; k <= N; k++) {
            dp[TAKE][k] = max(dp[TAKE][k-1], 0) + data[((k + i <= N) ? (k + i) : (k + i - N))];
            dp[LEAVE][k] = max(dp[TAKE][k-1], dp[LEAVE][k-1]);
        }
        int maxx = max(dp[TAKE][N], dp[LEAVE][N]);
        ans = max(ans, maxx);
    }

    cout << ans << nl;

    return 0;
}
