#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define nl '\n'

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        vector<int> second(26, 0);

        string a, b;
        cin >> a >> b;

        for (int i = 0; i < b.length(); i++) {
            second[b[i] - 'a']++;
        }

        int ans = 0;
        for (int i = 0; i < a.length(); i++) {
            if (second[a[i] - 'a'] > 0) {
                ans++;
                second[a[i] - 'a']--;
            } else {
                break;
            }
        }
        
        cout << ans << nl;
    }
    return 0;
}
