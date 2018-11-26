#include <bits/stdc++.h>

using namespace std;

#define nl "\n";

int main() {
    vector<int> creaturesMet(1001, 0);
    vector<int> weaponsToAskFor(1000);
    int n;

    cin >> n;
    int numWeapons = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a >= 0) {
            creaturesMet[a]++;
        } else {
            if (creaturesMet[-a] > 0) {
                creaturesMet[-a]--;
            } else if (creaturesMet[0] > 0) {
                creaturesMet[0]--;
                weaponsToAskFor[numWeapons] = -a;
                numWeapons++;
            } else {
                cout << "No" << nl;
                return 0;
            }
        }
    }

    cout << "Yes" << nl;
    for (int i = 0; i < creaturesMet[0]; i++) {
        weaponsToAskFor[numWeapons] = 69;
        numWeapons++;
    }
    for (int i = 0; i < numWeapons; i++) {
        cout << weaponsToAskFor[i] << " ";
    }
    cout << nl;
    return 0;
}
