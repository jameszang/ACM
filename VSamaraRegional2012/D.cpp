#include <bits/stdc++.h>

using namespace std;

#define nl '\n'

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(NULL);
    //cin.rdbuf(ifstream("input.txt").rdbuf());
    //cout.rdbuf(ofstream("output.txt").rdbuf());

    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");

    int n, k;
    in >> n >> k;
    int ans = 0;
    long long count = 1;
    while (count < n) {
        ans++;
        count += (count * k);
    }
    
    out << ans << nl;
    in.close();
    out.close();
    return 0;
}
