#include <iostream>
#include <vector>

using namespace std;

#define nl '\n'

int main() {
    int N;
    cin >> N;

    vector<int> v;
    v.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int T;
    cin >> T;

    int min = T % v[0];
    int ans = v[0];

    for (int i = 1; i < N; i++) {
        int temp = T % v[i];
        if (temp < min) {
            min = temp;
            ans = v[i];
        }
    }

    cout << ans << nl;
    return 0;
}
