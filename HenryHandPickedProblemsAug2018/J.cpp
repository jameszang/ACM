#include <bits/stdc++.h>

#define nl '\n'
#define MAX 2e4

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(MAX+1, vector<int>());

    for (int i = 1; i <= MAX; i++) {
        if (i <= 1e4) {
            graph[i].push_back(i * 2);
        }
        if (i > 1) {
            graph[i].push_back(i - 1);
        }
    }

    queue<int> q;
    vector<int> distance(MAX+1, -1);
    q.push(n);
    distance[n] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == m) {
            break;
        }

        for (int i = 0; i < graph[curr].size(); i++) {
            if (distance[graph[curr][i]] == -1) {
                q.push(graph[curr][i]);
                distance[graph[curr][i]] = distance[curr] + 1;
            }
        }
    }

    cout << distance[m] << nl;

    return 0;
}
