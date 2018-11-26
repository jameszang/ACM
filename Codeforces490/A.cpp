#include <iostream>
#include <vector>

using namespace std;

#define nl '\n'

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    int ans = 0;
    auto it_front = v.begin();
    auto it_back = v.end() - 1;

    while (*it_front <= k && it_front != v.end()) {
        ans++;
        it_front++;
    }

    if (it_front != v.end()) {
        while(*it_back <= k && it_back != it_front) {
            ans++;
            it_back--;
        }
    }

    cout << ans << nl;

    return 0;
}
