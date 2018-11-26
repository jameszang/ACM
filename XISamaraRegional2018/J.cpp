#include <iostream>
#include <unordered_map>

using namespace std;

#define nl '\n'

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> sticks;

    bool waiting = false;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        auto it = sticks.find(temp);
        if (it != sticks.end()) {
            if (sticks[temp] == 0) {
                sticks[temp] = 1;
            } else {
                if (waiting) {
                    count++;
                }
                waiting = !waiting;
                sticks[temp] = 0;
            }
        } else {
            sticks[temp] = 1;
        }
    }

    cout << count << nl; 

    return 0;
}
