#include <bits/stdc++.h>

using namespace std;

#define nl '\n'

int main() {
    string s;
    cin >> s;
    
    char last = s[0];
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == last) {
            cout << "Or not." << nl;
            return 0;
        } else {
            last = s[i];
        }
    }
    cout << "Odd." << nl;
    return 0;
}
