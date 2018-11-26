#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

int main() {
    string s;
    cin >> s;

    string display;
    display.resize(s.length());
    for (int i = 0; i < display.length(); i++) {
        display[i] = '_';
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char guess;
        cin >> guess;

        for (int i = 0; i < display.length(); i++) {
            if (display[i] == '_' && s[i] == guess) {
                display[i] = guess;
            }
        }
        cout << display << nl;
    }

    return 0;
}
