#include <bits/stdc++.h>

using namespace std;

#define nl '\n'

int main() {
    int n, X;
    double v;

    cin >> n >> X >> v;

    double sum = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        double vv;
        cin >> l >> r >> vv;
        
        sum += ((r - l) * vv);
    }

    double arcsin = -sum / (X*v);
    if (abs(arcsin) > 1) {
        cout << "Too hard" << nl;
        return 0;
    }
    double theta = asin(arcsin);
    double t = X / (v * cos(theta));
    
    if (t > (2*X/v)) {
        cout << "Too hard" << nl;
    } else {
        cout << fixed << setprecision(3) << t << nl;
    }
    return 0;
}
