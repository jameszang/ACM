#include <iostream>
#include <unordered_map>

using namespace std;

#define nl '\n'

// MAGIC IO
inline char get(void) {
	static char buf[100000], *S = buf, *T = buf;
	if (S == T) {
		T = (S = buf) + fread(buf, 1, 100000, stdin);
		if (S == T) return EOF;
	}
	return *S++;
}
inline void read(int &x) {
	static char c; x = 0; int sgn = 0;
	for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
	for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
	if (sgn) x = -x;
}
void readchar(char& c) {
	while (isspace(c = get()));
}
// END MAGIC IO

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    //read(T);

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        //read(n);

        unordered_map<int, int> rows; //maps row number to number of matrices with that row number
        unordered_map<int, int> cols; //maps col number to number of matrices with that col number
        for (int i = 0; i < n; i++) {
            int row, col;
            cin >> row >> col;
            //read(row); read(col);
            rows[row]++;
            cols[col]++;
            /* 
            auto it_row = rows.find(row);
            if (it_row != rows.end()) {
                it_row->second++;
            } else {
                rows[row] = 1;
            }

            auto it_col = cols.find(col);
            if (it_col != cols.end()) {
                it_col->second++;
            } else {
                cols[col] = 1;
            }
            */
        }

        long long ans = 0;
        for (auto pii : rows) {
            ans += ((long long) pii.second * cols[pii.first]);
        }
        cout << ans << nl;
    }
    return 0;
}
