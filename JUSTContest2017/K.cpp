#include <iostream>
#include <cmath>

using namespace std;

#define nl '\n'

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        double m;
        cin >> n >> m;

        int p = 0;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            if (temp >= 50) {
                p++;
            }
        }

        cout << ((p >= (ceil(n*m))) ? "YES" : "NO") << nl;
    }
    return 0;
}
