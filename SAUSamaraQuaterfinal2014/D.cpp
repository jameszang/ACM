#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n+1, 0);
    unordered_map<int, int> colorCounts;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        colorCounts[a[i]]++;
    }

    int m;
    cin >> m;

    if (colorCounts.size() == 1) {
        cout << 0 << nl;
        return 0;
    }

    for (int i = 1; i <= m; i++) {
        int k, x;
        cin >> k >> x;

        int temp = a[k];
        a[k] = x;

        if (temp != x) {
            colorCounts[x]++;
            colorCounts[temp]--;
            auto it = colorCounts.find(temp);
            if (it != colorCounts.end() && it->second == 0) {
                colorCounts.erase(it);
            }
        }
        if (colorCounts.size() == 1) {
            cout << i << nl;
            return 0;
        }
    }
    cout << -1 << nl;
    return 0;
}
