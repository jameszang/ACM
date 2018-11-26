#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define nl '\n'

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        map<string, int> m;
        for (int i = 0; i < N; i++) {
            string key;
            int val;

            cin >> key >> val;

            auto it = m.find(key);
            if (it != m.end()) {
                if (val < it->second) {
                    m[key] = val;
                }
            } else {
                m.emplace(key, val);
            }
        }

        vector<int> v;
        for (auto p : m) {
            v.push_back(p.second);
        }

        sort(v.begin(), v.end());

        for (auto i : v) {
            cout << i << " ";
        }
        cout << nl;
    }
}
