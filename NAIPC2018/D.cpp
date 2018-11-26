#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define nl '\n'

int main() {
    int n, m;
    cin >> n >> m;

    queue<int> gnomes;
    vector<int> tracker(n+1, 0);
    
    for (int i = 0; i < m; i++) {
        int g;
        cin >> g;

        gnomes.push(g);
        tracker[g] = 1;
    }

    queue<int> toAdd;
    for (int i = 1; i < n+1; i++) {
        if (tracker[i] == 0) {
            toAdd.push(i);
        }
    }
    

    while (!gnomes.empty() && !toAdd.empty()) {
        int a = gnomes.front();
        int b = toAdd.front();
        if (a < b) {
            cout << a << nl;
            gnomes.pop();
        } else {
            cout << b << nl;
            toAdd.pop();
        }
    }

    while (!gnomes.empty()) {
        cout << gnomes.front() << nl;
        gnomes.pop();
    }

    while (!toAdd.empty()) {
        cout << toAdd.front() << nl;
        toAdd.pop();
    }
    return 0;
}
