#include <bits/stdc++.h>

using namespace std;

#define nl '\n'

int main() {
    // floors, start, goal, up, down
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    
    vector<vector<int>> graph(f+1, vector<int>());

    //generate graph
    for (int i = 1; i <= f; i++) {
        if ((i + u) <= f) {
            graph[i].push_back(i + u);
        }
        if ((i - d) >= 1) {
            graph[i].push_back(i - d);
        }
    }

    //BFS
    queue<int> q;
    vector<int> distances(f+1, -1);
    vector<bool> visited(f+1, false);
    q.push(s);
    distances[s] = 0;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (!visited[curr]) {
            visited[curr] = true;
            for (int i = 0; i < graph[curr].size(); i++) {
                int neighbour = graph[curr][i];
                q.push(neighbour);
                if (distances[neighbour] == -1) {
                    distances[neighbour] = distances[curr] + 1;
                }
            }
        }
    }
    
    if (distances[g] != -1) {
        cout << distances[g] << nl;
    } else {
        cout << "use the stairs"  << nl;
    }
}
