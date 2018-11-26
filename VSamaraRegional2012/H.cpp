#include <bits/stdc++.h>

using namespace std;

#define nl '\n'

pair<int, int> solve(string s, int k) {
    if (s.length() <= k) {
        return make_pair(1, s.length());
    }

    unordered_map<char, int> m;
    int maxLength = k;
    int l = 0;
    int lp = 0; //remember to convert to 1 index later

    for (int i = 0; i < s.length(); i++) {
        auto it = m.find(s[i]);
        if (it != m.end()) {
            m[s[i]]++;
        } else {
            m[s[i]] = 1;
        }

        if (m.size() > k) {
            if ((i - l) > maxLength) {
                lp = l;
                maxLength = (i - l);
            }
            while (m.size() > k) {
                char c = s[l];
                if (m[c] == 1) {
                    m.erase(c);
                } else {
                    m[c]--;
                }
                l++;
            }
        }
    }

    if ((s.length()-l) > maxLength) {
        lp = l;
        maxLength = (s.length() - l);
    }

    return make_pair(lp+1, lp + maxLength);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int k;
    string s;
    cin >> k >> s;
    
    pair<int, int> ans = solve(s, k);
    cout << ans.first << " " << ans.second << nl;
    return 0;
}
