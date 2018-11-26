#include <bits/stdc++.h>

using namespace std;

#define nl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    int numOdd = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        if (temp % 2 == 1) {
            numOdd++;
        }
    }

    if ((numOdd % 2) == (n % 2)) {
        cout << "Mike" << nl;
    } else {
        cout << "Constantine" << nl;
    }
    return 0;
}
