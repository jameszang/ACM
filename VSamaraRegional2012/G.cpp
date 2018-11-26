#include <bits/stdc++.h>

using namespace std;

#define nl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int k, n;
    cin >> k >> n;
    vector<pair<int, int>> v; //pair<numQuestions, subjectID>
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.emplace_back(temp, i);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        if (k <= 0) {
            break;
        }

        int numCanLearn = min(k, v[i].first);
        ans[v[i].second] += numCanLearn;
        k -= numCanLearn;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    cout << nl;

    return 0;
}
