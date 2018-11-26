#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define nl '\n'

int reverseSubstr(string & s, int start, int end) {
    int i = start;
    int j = end;
    while (i < j) {
        swap(s[i], s[j]);
        i++;
        j--;
    }
}

int main() {
    string s, t;
    cin >> s >> t;

    int n = s.length();

    int start;
    int end;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            start = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != t[i]) {
            end = i;
            break;
        }
    }

    if (start >= end) {
        cout << "YES" << nl;
        return 0;
    }

    reverseSubstr(t, start, end);

    if (s == t) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
    }

    return 0;
}
