#include <iostream>
#include <vector>

using namespace std;

#define nl '\n'

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid;
    grid.resize(n);
    for (int i = 0; i < n; i++) {
        vector<char> v;
        v.resize(m);
        grid[i] = v;
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<bool> visitedRows(n, false);
    vector<bool> visitedCols(m, false);

    bool good = true;
    for (int i = 0; i < n; i++) {
        if (!visitedRows[i]) {
            visitedRows[i] = true;
            for (int j = i; j < n; j++) {
                if (grid[i] == grid[j]) {
                    visitedRows[j] = true;
                }
            }
            for (int k = 0; k < m; k++) {
                if (grid[i][k] == '#') {
                    if (visitedCols[k]) {
                        good = false;
                        break;
                    } else {
                        visitedCols[k] = true;
                    }
                }
            }
            if (!good) {
                break;
            }
        }
    }

    if (good) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
    }

    return 0;
}
