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

        vector<vector<int>> diagonals;
        diagonals.resize(n+m-1);
       
        int currDiagonal = 0;
        int currDiagonalCapacity = 1;
        int numMaxCapacity = 0;
        for (int i = n * m; i > 0; i--) {
            diagonals[currDiagonal].push_back(i);
            if (diagonals[currDiagonal].size() >= currDiagonalCapacity) {
                if (currDiagonalCapacity <= min(n,m)) {
                    currDiagonalCapacity++;
                } else if (numMaxCapacity < abs(n-m)+1) {
                    numMaxCapacity++;
                } else {
                    currDiagonalCapacity--;
                }
                currDiagonal++;
            }
        }

        int temp = 0;
        for (int i = 0; i < 20; i++) {
            for (vector<int> v : diagonals) {
                if (i < v.size()) {
                    cout << v[i] << ' ';
                    temp++;
                
                    if (temp >= m) {
                        cout << nl;
                        temp = 0;
                    }
                }
            }
        }
    }
    return 0;
}
