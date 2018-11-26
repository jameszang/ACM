#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

int main() {
    int k;
    cin >> k;

    if (k % 2 == 1) {
        cout << 1 << nl;
        cout << 2*k << " " << 2*k << nl;
    } else {
        cout << 3 << nl;
        cout << 2*k << " " << 2*k << nl;
        cout << 3*k << " " << (3*k) / 2 << nl;
        cout << (3*k) / 2 << " " << 3*k << nl;
    }

    return 0;
}

