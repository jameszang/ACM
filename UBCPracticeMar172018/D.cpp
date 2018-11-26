#include <iostream>
#include <cmath>

using namespace std;

#define nl '\n'

int main() {
    int n;
    cin >> n;

    int ans = ceil(log2(n)) + 1;
    cout << ans << nl;
    return 0;
}

int log2(int n) {
    return log((double) n) / log(2.0);
}
