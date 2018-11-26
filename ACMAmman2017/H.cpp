#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define nl '\n'

void odd(int n, int s) {
    string ans;
    ans.resize(n);
    int temp = s / 2;
    int remaining = s;
    for (int i = 0; i < (n / 2); i++) {
        int num = min(temp, 9);
        ans[i] = num + '0';
        ans[n - i - 1] = num + '0';
        temp -= num;
        remaining -= num;
        remaining -= num;
    }
    ans[n/2] = remaining + '0';

    cout << (ans[0] == '0' ? "-1" : ans) << nl;
}

void even(int n, int s) {
    if (s % 2 != 0) {
        cout << -1 << nl;
        return;
    }

    string ans;
    ans.resize(n);
    int temp = s / 2;
    for (int i = 0; i < (n / 2); i++) {
        int num = min(temp, 9);
        ans[i] = num + '0';
        ans[n - i - 1] = num + '0';
        temp -= num;
    }

    cout << (ans[0] == '0' ? "-1" : ans) << nl;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n, s;
        cin >> n >> s;

        //sanity check
        if (s > (n * 9)) {
            cout << -1 << nl;
            continue;
        }

        if (n % 2 == 0) {
            even(n, s);
        } else {
            odd(n, s);
        }
    }
    return 0;
}
