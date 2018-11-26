#include <iostream>
#include <unordered_map>

using namespace std;

#define nl '\n'

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        unordered_map<int, int> m;
        int N;
        cin >> N;

        for (int i = 0; i < N; i++) {
            string s;
            int freq;
            cin >> s >> freq;

            auto it = m.find(freq);
            if (it != m.end()) {
                it->second++;
            } else {
                m[freq] = 1;
            }
        }

        auto it = m.begin();
        int maxNum = it->second;
        int maxFreq = it->first;
        it++;

        while (it != m.end()) {
            if (it->second > maxNum) {
                maxNum = it->second;
                maxFreq = it->first;
            } else if (it->second == maxNum) {
                if (it->first < maxFreq) {
                    maxNum = it->second;
                    maxFreq = it->first;
                }
            }
            it++;
        }

        cout << maxFreq << nl;
    }
    return 0;
}
