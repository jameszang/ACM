#include <bits/stdc++.h>

using namespace std;

#define nl '\n'

int main() {
    int t;
    cin >> t;

    if (t >= 100) { 
        cout.precision(15);
        cout << 19.4896044934771 << nl;
        return 0;
    }

    double ans = 0;
    for (int k = 1; k <= t; k++) {
        double num1 = exp(-k) * pow(k, 2+sqrt(k));
        double num2 = exp(-k) * pow(k, sqrt(k)) * sin(k);
        double denom = 1 - exp(-k);

        ans += ((num1 + num2) / denom);
    }

    double toPrint = max(0.0, 100 - ans);
    cout.precision(15);
    cout << toPrint << nl;

    return 0;
}
