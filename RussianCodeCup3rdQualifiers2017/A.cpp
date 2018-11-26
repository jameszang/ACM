#include <iostream>
#include <vector>

using namespace std;

#define nl '\n'

int main() {
    int t;
    cin >> t;
    vector<char> map(27);

    for (int i = 1; i < map.size(); i++) {
        map[i] = (char)('A' + i - 1);
    }

    for (int i = 0; i < t; i++) {
        vector<char> column;
        int k;
        cin >> k;

        while (k > 0) {
            int mod = k % 26;
            if (mod == 0) {
                column.push_back(map[26]);
                k--;
            } else {
                column.push_back(map[mod]);
            }
            k /= 26;
        }

        for (int j = column.size() - 1; j >= 0; j--) {
            cout << column[j];
        }
        cout << nl;
    }
}
