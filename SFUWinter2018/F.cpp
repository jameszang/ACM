#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define nl '\n'

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        vector<int> points(N+1, 0);
        for (int i = 0; i < ((N-2) * (N/2)); i++) {
            int a, b;
            char status;

            cin >> a >> b >> status;

            if (status == 'W') {
                points[a] += 3;
            } else if (status == 'L') {
                points[b] += 3;
            } else {
                points[a]++;
                points[b]++;
            }
        }


    }
    return 0;
}
