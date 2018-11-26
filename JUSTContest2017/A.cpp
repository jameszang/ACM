#include <iostream>

using namespace std;

#define nl '\n'

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int y, x;
        cin >> y >> x;

        cout << ((y * 100) / (100 + x)) << nl;
    }
    return 0;
}
