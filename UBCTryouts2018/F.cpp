#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

double binarySearch(double low, double high, double find) {
    double mid = (low + high) / 2;
    if (abs(mid - find) < 1e-8) {
        return mid;
    } else {
        if (find > mid) {
            return binarySearch(mid, high, find);
        } else {
            return binarySearch(low, mid, find);
        }
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    double v = sqrt(((double) c) / a);
    double ans = v / ((a * v * v) + (b * v) + c);

    cout << setprecision(10) << v << nl << ans << nl;

    return 0;
}
