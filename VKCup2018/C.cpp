#include <iostream>

using namespace std;

#define nl '\n'

int main() {
    bool good = true;
    int n;
    cin >> n;

    int numFirst = 0;
    int a;
    cin >> a;
    int first = a;
    numFirst++;
    while (a == first && numFirst < n) {
        cin >> a;
        if (a != first) {
            break;
        }
        numFirst++;
    }
    int count = 0;
    int curr = a;
    count++;
    for (int i = 0; i < n - numFirst - 1; i++) {
        cin >> a;
        if (a == curr) {
            count++;
        } else {
            if (count != numFirst) {
                good = false;
                break;
            } else {
                curr = a;
                count = 1;
            }
        }
    }

    if (numFirst != n && count != numFirst) {
        good = false;
    }
    if (good) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
    }
    return 0;
}
