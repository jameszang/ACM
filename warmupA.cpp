#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        vector<int> odds;
        vector<int> evens;
        for (int i = 1; i <= N; i++) {
            int num;
            cin >> num;

            if (num % 2 == 1) {
                odds.push_back(i);
            } else {
                evens.push_back(i);
            }
        }

        cout << ((odds.size() == 1) ? odds[0] : evens[0]) << nl;
    }

    return 0;
}
