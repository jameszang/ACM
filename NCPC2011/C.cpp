#include <bits/stdc++.h>

using namespace std;

#define nl '\n'

int main() {
    int n;
    cin >> n;

    int ans = n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        bool check = false;
        for (int j = 0; j < s.length(); j++) {
            if (check) {
                if (s[j] == 'D') {
                    ans--;
                    break;
                } else if (s[j] == 'C') {
                    check = true;
                } else {
                    check = false;
                }
            } else if (s[j] == 'C') {
                check = true;
            } else {
                check = false;
            }
        }
    }

    cout << ans << nl;
}
