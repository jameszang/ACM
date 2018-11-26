#include <iostream>
#include <unordered_map>
#include <iomanip>

using namespace std;

#define nl '\n'

int main() {
    
    unordered_map<int, double> m = {
    {0, 2.000000000},
    {1, 1.000000000},
    {2, 0.500000000},
    {4, 0.250000000},
    {8, 0.125000000},
    {16, 0.062500000}
    };
    
    int N;
    cin >> N;

    double ans = 0;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        ans += m[temp];
    }

    cout << fixed;
    cout << setprecision(9) <<  ans << nl;
    return 0;
}
