#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define nl '\n'

int main() {
    int t;
    cin >> t;

    for (int test = 0; test < t; test++) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> v(n);
        for (vector<int>& vv : v) {
            vv.resize(m);
        }
        int num = n * m;
        for (int col = 0; col < n+m; col++) {
            int temp = col;
            for (int row = 0; row < n; row++) {
                if ((temp >= 0) && (temp < m) && (row >= 0) && (row < n)) {
                    v[row][temp] = num;
                    num--;
                }
                temp--;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << v[i][j] << " ";
            }
            cout << nl;
        }
    }
    return 0;
}
