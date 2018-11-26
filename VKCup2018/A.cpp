#include <iostream>
#include <set>
#include <queue>

using namespace std;

#define nl '\n'

int main() {
    long long l, r;
    cin >> l >> r;

    queue<long long> q;
    set<long long> visited;
    int count = 0;

    q.push(1);
    while (!q.empty()) {
        long long curr = q.front();
        q.pop();
        if (curr <= r && visited.count(curr) != 1) {
            if (curr >= l) {
                count++;
            }
            q.push(curr * 2);
            q.push(curr * 3);
            visited.insert(curr);
        }
    }
    cout << count << nl;
    return 0;
}
