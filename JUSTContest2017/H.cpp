#include <iostream>
#include <cmath>

using namespace std;

#define nl '\n'

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << (((b * log(a)) < (d * log(c))) ? "<" : ">") << nl;
    }
    return 0;
}
