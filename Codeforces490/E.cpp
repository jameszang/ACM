#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define nl '\n'

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<int>> graph(n+1, vector<int>());
    vector<vector<int>> backtrack(n+1, vector<int>());

    for (int i = 0; i < m; i++) {
        int src, dest;
        cin >> src >> dest;
        graph[src].push_back(dest);
        backtrack[dest].push_back(src);
    }

    //BFS
    queue<int> q;
    vector<bool> visited(n+1, false);
    q.push(s);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        if (!visited[curr]) {
            visited[curr] = true;
            for (int i = 0; i < graph[curr].size(); i++) {
                q.push(graph[curr][i]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && backtrack[i].empty()) {
            ans++;
            visited[i] = true;
        } else if (!visited[i] && !backtrack[i].empty()) {
            
        }
    }

    cout << ans << nl;
    return 0;
}
