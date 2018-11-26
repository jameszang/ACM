#include <bits/stdc++.h>

#define nl '\n'
#define INF 0x3f3f3f3f

enum vacation {
    REST = 0,
    CONTEST = 1,
    GYM = 2
};

using namespace std;

int main() {
    int n;
    cin >> n;
    
    //dp[i][j] where i == day and j == activity
    vector<vector<int>> dp(n+1, vector<int>(3, INF));
    dp[0][REST] = 0;

    for (int i = 1; i <= n; i++) {
        int curr;
        cin >> curr;

        switch(curr) {
            case 0: {
                dp[i][REST] = min(dp[i-1][REST], min(dp[i-1][CONTEST], dp[i-1][GYM])) + 1;
                dp[i][CONTEST] = INF;
                dp[i][GYM] = INF;
                break;
            }
            case 1: {
                dp[i][REST] = min(dp[i-1][REST], min(dp[i-1][CONTEST], dp[i-1][GYM])) + 1;
                dp[i][CONTEST] = min(dp[i-1][REST], dp[i-1][GYM]);
                dp[i][GYM] = INF;
                break;
            }
            case 2: {
                dp[i][REST] = min(dp[i-1][REST], min(dp[i-1][CONTEST], dp[i-1][GYM])) + 1;
                dp[i][CONTEST] = INF;
                dp[i][GYM] = min(dp[i-1][REST], dp[i-1][CONTEST]);
                break;
            }
            default: {
                dp[i][REST] = min(dp[i-1][REST], min(dp[i-1][CONTEST], dp[i-1][GYM])) + 1;
                dp[i][CONTEST] = min(dp[i-1][REST], dp[i-1][GYM]);
                dp[i][GYM] = min(dp[i-1][REST], dp[i-1][CONTEST]);
                break;
            }
        }
    }

    cout << min(dp[n][REST], min(dp[n][CONTEST], dp[n][GYM])) << nl;

    return 0;
}
