#include <iostream>
#include <vector>

using namespace std;

#define nl '\n'
#define INF 0x3f3f3f3f
typedef pair<int,int> pii;

int main() {
    int n;
    cin >> n;

    vector<int> map(n+1, -1);
    vector<int> after;
    after.push_back(-1);

    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        map[temp] = i;
    }

    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        after.push_back(map[temp]);
    }

    vector<int> lis(n+1, INF);
    lis[0] = -1;
    
    for (int i = 1; i <= n; i++) {
        vector<int>::iterator minInLis = lower_bound(lis.begin(), lis.end(), after[i]);
        int pos = minInLis - lis.begin();
        lis[pos] = after[i];
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (lis[i] == INF) {
            break;
        }
        count++;
    }

    cout << count << nl;

    return 0;
}
