#include <iostream>
#include <string>

using namespace std;

#define nl '\n'

int main() {
    int n;
    string s;

    cin >> n >> s;

    bool good = false;
    char lastChar = 'X';
    char lastRealChar = 'X';
    bool inBlock = false;
    int count = 0;
    for (unsigned i = 0; i < n; i++) {
        if (s[i] == '?' && lastChar == 'X') {
            good = true;
        }
        if (s[i] == '?') {
            inBlock = true;
            count++;
        } else {
            if (lastChar == s[i]) {
                cout << "NO" << nl;
                return 0;
            } 
            inBlock = false;
            if (count >= 2) {
                good = true;
            } else if (count >= 1 && lastRealChar == s[i]) {
                good = true;
            } else {
                count = 0;
                lastRealChar = s[i];
            }
        }
        lastChar = s[i];
    }
    
    if (good) {
        cout << "YES" << nl;
        return 0;
    } 

    if (inBlock) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
    }

    return 0;
}
