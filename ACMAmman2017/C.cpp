#include <iostream>
#include <string>

using namespace std;

#define nl '\n'

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int a, b, c;
        cin >> a >> b >> c;

        int min = (a < b ? a : b);
        string ans = (a < b ? "First" : "Second");

        min = (min < c ? min : c);
        ans = (min < c ? ans : "Third");

        cout << ans << nl;
    }
    return 0;
}
