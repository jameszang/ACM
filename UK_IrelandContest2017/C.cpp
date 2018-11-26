#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define nl '\n'

int main() {
    unordered_map<string, int> m = {
        {"red", 1},
        {"yellow", 2},
        {"green", 3},
        {"brown", 4},
        {"blue", 5},
        {"pink", 6},
        {"black", 7}
    };
    int N;
    cin >> N;

    vector<int> v(8, 0);
    
    int largestSeen = 1;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;

        v[m[temp]]++;
        if (m[temp] > largestSeen) {
            largestSeen = m[temp];
        }
    }

    if (largestSeen == 1) {
        cout << 1 << nl;
    } else {
        int ans = 0;
        ans += ((v[1]+1) * largestSeen);
        ans += v[1];
        for (int i = 2; i < largestSeen; i++) {
            ans += (v[i] == 1 ? i : 0);
        }
        cout << ans << nl;
    }
    return 0;
}
