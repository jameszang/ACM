#include <iostream>

using namespace std;

#define nl '\n'

int main() {
    int s, g;
    cin >> s >> g;

    if ((s % g) != 0) {
        cout << -1 << nl;
        return 0;
    }

    int factor = s / g;

    if (factor <= 1) {
        cout << -1 << nl;
        return 0;
    }

    cout << (factor - 1) * g << " " << g << nl;

    return 0;
}
