#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define nl '\n'

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string l, r;
        cin >> l >> r;

        int count = 0;
        if (l.length() == 1 && r.length() == 1) {
            int lNum = l[0] - '0';
            int rNum = r[0] - '0';
            count += (rNum - lNum + 1);
        } else {
            if (l.length() == 1) {
                int lNum = l[0] - '0';
                count += (10 - lNum);
                l = "10";
            }
            while (l.length() != r.length()) {
                int variableDigits = l.length() - 2;
                int toAdd = 9;
                for (int j = 0; j < variableDigits; j++) {
                    toAdd *= 10;
                }
                count += toAdd;
                l[0] = '1';
                for (int j = 1; j < l.length(); j++) {
                    l[j] = '0';
                }
                l.push_back('0');
            }
            
            int lNum = l[0] - '0';
            int rNum = r[0] - '0';
            int lLast = l[l.length() - 1] - '0';
            int rLast = r[r.length() - 1] - '0';
            int toAdd;
            if (rLast > lLast) {
                toAdd = rNum - lNum;
            } else {
                toAdd = rNum - lNum - 1;
            }
            for (int j = 0; j < l.length() - 2; j++) {
                toAdd *= 10;
            }
            count += toAdd;

            toAdd = 0;
            while (lLast <= rLast) {
                if (lLast == lNum) {
                    toAdd++;
                }
                lLast++;
            }
            for (int j = 1; j < l.length() - 2; j++) {
                int diff = r[j] - l[j];

                toAdd *= (r[j] - l[j]);
            }
            count += toAdd;
        }
        cout << count << nl;
    }
}
