#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define nl '\n'

int main() {
    int n;
    string t;
    cin >> n >> t;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            reverse(t.begin(), t.begin() + i);
            //cerr << t << nl;
        }
    }

    cout << t << nl;

    return 0;
}
