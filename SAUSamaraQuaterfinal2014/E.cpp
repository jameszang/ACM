#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> counts(26, 0);

    for (int i = 0; i < s.length(); i++) {
        counts[s[i] - 'a']++;    
    }

    bool good = true;
    if (s.length() % 2 == 1) {
        good = false;
    }
    
    if (good) {
        for (int i = 0; i < 26; i++) {
            if (counts[i] > s.length() / 2) {
                good = false;
                break;
            }
        }
    }

    if (good) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
    }
    return 0;
}
