#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> ans(n, -1);
    ans[n-1] = 1;
    unordered_set<int> seen;
    seen.insert(a[n-1]);
    for (int i = n-2; i >= 0; i--) {
        if (seen.count(a[i]) == 1) {
            ans[i] = ans[i+1];
        } else {
            seen.insert(a[i]);
            ans[i] = ans[i+1] + 1;
        }
    }

    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;

        cout << ans[q-1] << nl;
    }
    
    return 0;
}
