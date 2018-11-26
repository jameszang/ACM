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
        string s;
        cin >> s;

        int count = 0;
        for (unsigned i = 0; i < s.length(); i++) {
            if (s[i] == 'U') {
                count++;
            } else {
                break;
            }
        }
        cout << count << nl;
    }
    return 0;
}
