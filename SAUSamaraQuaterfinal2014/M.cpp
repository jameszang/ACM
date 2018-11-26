#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << a * b << nl;

    vector<int> numbers (a*b, 0);
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            numbers[j*a + i] = b - j + i*b; 
        }
    }

    for(int i = 0; i < a*b; i++) {
        cout << numbers[i] << " ";
    }
    cout << nl;
    return 0;
}

