#include <iostream>

using namespace std;

#define nl '\n'

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n, k;
        cin >> n >> k;
        cout << n + k - 1 << nl;
    }
    return 0;
}
