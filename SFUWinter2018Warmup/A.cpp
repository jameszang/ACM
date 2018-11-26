#include <iostream>
#include <vector>

using namespace std;

#define nl '\n'

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        vector<int> numbers;
        numbers.resize(N+1);
        for (int i = 1; i <= N; i++) {
            cin >> numbers[i];
        }
        
        int first = numbers[1];
        int second = numbers[2];
        int third = numbers[3];
        int even;
        
        int firstmod = first % 2;
        int secondmod = second % 2;
        int thirdmod = third % 2;
        if (firstmod != secondmod) {
            if (firstmod != thirdmod) {
                cout << 1 << nl;
            } else {
                cout << 2 << nl;
            }
            continue;
        } else if (firstmod != thirdmod) {
            if (firstmod != secondmod) {
                cout << 1 << nl;
            } else {
                cout << 3 << nl;
            }
            continue;
        } else if (secondmod != thirdmod) {
            if (secondmod != firstmod) {
                cout << 2 << nl;
            } else {
                cout << 3 << nl;
            }
            continue;
        }

        even = firstmod;

        for (int i = 4; i <= N; i++) {
            if ((numbers[i] % 2) != even) {
                cout << i << nl;
                break;
            }
        }
    }
}
