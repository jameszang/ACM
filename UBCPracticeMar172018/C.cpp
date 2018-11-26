#include <iostream>
#include <cstring>

using namespace std;

#define nl '\n'

int main() {
    string str;
    cin >> str;
    char *s = &str[0];
    //char s[100001];
    //memset(s, 0, 100001);
    //cin >> s;
    int len = strlen(s);
    int **LCSuffix = new int*[len+1];
    for(int i = 0; i < len+1; i++) {
        LCSuffix[i] = new int[len+1];
    }
    //int LCSuffix[len+1][len+1];
    
    for (int i = 0; i <= len; i++) {
        for (int j = 0; j <= len; j++) {
            if (i == 0 || j == 0) {
                LCSuffix[i][j] = 0;
            } else if (s[i-1] == s[j-1]) {
                LCSuffix[i][j] = LCSuffix[i-1][j-1] + 1;
            } else {
                LCSuffix[i][j] = 0;
            }
        }
    }
    
    int q;
    cin >> q;

    for (int t = 0; t < q; t++) {
        int i, j;
        cin >> i >> j;
        
        int ans = 0;
        for (int x = i, y = j; y < len; x++, y++) {
            if (x >= len || y >= len || LCSuffix[x+1][y+1] == 0) {
                break;
            }
            ans++;
        }
        cout << ans << nl;
    }
    for (int i = 0; i < len+1; i++) {
        delete[] LCSuffix[i];
    }
    delete[] LCSuffix;
    return 0;
}
