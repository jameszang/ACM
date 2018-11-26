#include <iostream>
#include <string>

using namespace std;

#define nl '\n'

int main() {
    int T;
    cin >> T;

    string nothing;
    getline(cin, nothing);

    for (int t = 0; t < T; t++) {
        string sentence;
        getline(cin, sentence);
        sentence.push_back(' ');
        
        bool good = false;
        for (int i = 2; i < sentence.length(); i++) {
            int curr = i - 1;
            bool valid = true;
            if (sentence.length() % i != 0) {
                continue;
            }
            while (curr < sentence.length()) {
                //cerr << sentence[curr] << " ";
                if (sentence[curr] != ' ') {
                    valid = false;
                    break;
                }
                curr += i;
            }
            //cerr << nl;
            if (valid) {
                good = true;
                break;
            }
        }

        if (good) {
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }
    }
    return 0;
}
