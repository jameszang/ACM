#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define WRONG "WRONGANSWER"

int main() {
    int n, k;
    string a;

    cin >> n >> k >> a;
    
    if (k > n) {
        cout << WRONG << nl;
        return 0;
    } else {
        vector<int> counts(26, 0);

        for(char c : a) {
            counts[c-'a']++;
        }

        int min = counts[0];
        char minChar = 'a';
        for (int i = 1; i < 26; i++) {
            if (counts[i] < min) {
                min = counts[i];
                minChar = i+'a';
            }
        }
        if (min > k) {
            cout << WRONG << nl;
            return 0;
        } else {
            string b(n, minChar);
            int index = 0;
            for (int i = min; i < k; i++, index++) {
                if (b[index] == a[index]) {
                    i--;
                }
                b[index] = a[index];
            }
            cout << b << nl;
            return 0;
        }
    }
}
