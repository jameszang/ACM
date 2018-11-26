#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if ((c % 2 == 1) || ((c / 2) < a)) {
        cout << "Take another envelope" << nl;
    } else if (c > b) {
        cout << "Stay with this envelope" << nl;
    } else {
        cout << "Take another envelope" << nl;
    }
    return 0;
}
