#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define nl '\n'

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        vector<int> data(3, 0);

        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            switch(s[0]) {
                case 'b':
                    data[0]++;
                    break;
                case 'k':
                    data[1]++;
                    break;
                default:
                    data[2]++;
                    break;
            }
        }
        cout << min(min(data[1], data[2]), (data[0] / 2)) << nl;
    }
    return 0;
}
