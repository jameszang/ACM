#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define nl '\n'

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<double> probs;
    for (int i = 0; i < n + m - 1; i++) {
        double p;
        cin >> p;
        probs.push_back(p);
    }

    sort(probs.begin(), probs.end());

    double ans = 0;
    do {
        double p_instance = 1;
        for (int i = 0; i < m; i++) {
            p_instance *= probs[i];
        }
        for (int i = m; i < n + m - 1; i++) {
            p_instance *= (1 - probs[i]);
        }
        ans += p_instance;
    } while (next_permutation(probs.begin(), probs.end()));
    cout << ans << nl;
}
