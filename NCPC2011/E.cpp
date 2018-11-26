#include <bits/stdc++.h>

using namespace std;

#define nl '\n'

int main() {
    string p;
    cin >> p;
    p.insert(0, "#");
    p.push_back('&');

    vector<string> pSplit;
    string s = "";
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '*') {
            if (s != "") {
                pSplit.push_back(s);
                s = "";
            }
            pSplit.push_back("*");
        } else {
            s.push_back(p[i]);
        }
    }
    if (s != "") {
        pSplit.push_back(s);
    }

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        int len = temp.length();
        temp.insert(0, "#");
        temp.push_back('&');

        int idxTemp = 0;
        int matches = 0;
        for (int j = 0; j < pSplit.size(); j++) {
            if (pSplit[j] != "*") {
                bool good = false;
                for (int k = idxTemp; k < temp.length() - pSplit[j].length() + 1; k++) {
                    if (temp.substr(k, pSplit[j].length()) == pSplit[j]) {
                        good = true;
                        idxTemp += pSplit[j].length();
                    } else {
                        idxTemp++;
                    }
                    if (good) {
                        matches++;
                        break;
                    }
                }
            } else {
                matches++;
            }
        }

        if (matches == pSplit.size()) {
            if ((pSplit[pSplit.size() - 1] == "*") || (idxTemp >= temp.length())) {
                cout << temp.substr(1, len) << nl;
            }
        }
    }
}
