#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define nl '\n'

int main() {
    string rows, cols;
    cin >> rows >> cols;

    vector< vector<char> > grid;
    vector< vector< pair<char,char> > > status;
    grid.resize(rows.length());
    status.resize(rows.length());
    for (int i = 0; i < rows.length(); i++) {
        grid[i].resize(cols.length());
        status[i].resize(cols.length());
    }

    for (int i = 0; i < rows.length(); i++) {
        for (int j = 0; j < cols.length(); j++) {
            if (((rows[i] == '1' && cols.length() % 2 == 0) || (rows[i] == '0' && cols.length() % 2 == 1)) && ((cols[j] == '1' && rows.length() % 2 == 0) || (cols[j] == '0' && rows.length() % 2 == 1))) {
                status[i][j] = make_pair('x', 'x');
            } else if ((rows[i] == '1' && cols.length() % 2 == 0) || (rows[i] == '0' && cols.length() % 2 == 1)) {
                status[i][j] = make_pair('x', 'o');
            } else if ((cols[j] == '1' && rows.length() % 2 == 0) || (cols[j] == '0' && rows.length() % 2 == 1)) {
                status[i][j] = make_pair('o', 'x');
            } else {
                status[i][j] = make_pair('o', 'o');
            }
        }
    }

    for (int i = 0; i < rows.length(); i++) {
        for (int j = 0; j < cols.length(); j++) {
            if (status[i][j].first == 'x' && status[i][j].second == 'x') {
                grid[i][j] = '0';
                for (int damn = 0; damn < cols.length(); damn++) {
                    status[i][damn].first = 'o';
                }
                for (int it = 0; it < rows.length(); it++) {
                    status[it][j].second = 'o';
                }
            } else {
                grid[i][j] = '1';
            }
        }
    }
        bool errorf = false;
        int i0f;
        int j0f;

        vector<int> j0f;
        vector<bool> errorf;
        j0f.resize(cols.length());
        errorf.resize(cols.length());

    for (int i = 0; i < rows.length(); i++) {

        bool errors = false;
        int i0s;
        int j0s;
        
        for (int j = 0; j < cols.length(); j++) {
            if (status[i][j].first == 'x' ) {
                if (!error) {
                    errorf[j]=true;
                    j0f[j]=i;
                } else {
                   grid[i0f][j0f]='0';
                   grid[i][j]='0';
                   errorf=false;
                }
                
            } 
            if (status[i][j].second == 'x') {
         
                        if (!error) {
                            errors=true;
                            i0s=i;
                            j0s=j;
                        } else {
                           grid[i0s][j0s]='0';
                           grid[i][j]='0';
                           errors=false;
                        }
                        
                    
                }
    
    }
    if (errors) {
        cout<<-1<<nl;
        return 0;
    }
    }

    for (int i = 0; i < rows.length(); i++) {
        for (int j = 0; j < cols.length(); j++) {
            cout << grid[i][j];
        }
        cout << nl;
    }
    return 0;
}
