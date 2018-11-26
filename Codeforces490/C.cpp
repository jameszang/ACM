#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define nl '\n'

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<vector<int>> v(26, vector<int>());
    for (int i = n-1; i >= 0; i--) {
        v[s[i] - 'a'].push_back(i);
    }

    int curr = 0;
    for (int i = 0; i < k; i++) {
        bool good = false;
        while (!good) {
            if (v[curr].empty()) {
                curr++;
            } else {
                int idx = v[curr].back();
                v[curr].pop_back();
                s[idx] = '0';
                good = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] != '0') {
            cout << s[i];
        }
    }

    cout << nl;

    return 0;
}
