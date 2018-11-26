#include <iostream>
#include <vector>
//#include <pair>
#include <queue>
#include <cmath>

using namespace std;

#define nl '\n'
//typedef pair<int, int> pii;

int main() {
    int t;
    cin >> t;

    for (int tt = 0; tt < t; tt++) {
        priority_queue<int> heroes; //stores damage dealt before dying
        int n, H, A;
        cin >> n >> H >> A;

        for (int i = 0; i < n; i++) {
            int hp, atk;
            cin >> hp >> atk;

            int damageDealt = (int)ceil((double)hp / A) * atk;
            heroes.push(damageDealt);
        }

        int deaths = 0;
        while (!heroes.empty() && H > 0) {
            int damage = heroes.top();
            H -= damage;
            if (H > 0) {
                deaths++;
                heroes.pop();
            }
        }

        if (heroes.empty()) {
            cout << -1 << nl;
        } else {
            cout << deaths << nl;
        }
    }
    return 0;
}
