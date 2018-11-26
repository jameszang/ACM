#include <iostream>

using namespace std;

#define nl '\n'

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;
        cout << (((n % 2 == 0) && (m % 2 == 0)) ? "abdullah" : "hasan") << nl;
    }
    return 0;
}
