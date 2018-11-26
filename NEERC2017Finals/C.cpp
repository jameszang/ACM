#include <bits/stdc++.h>

using namespace std;

#define nl "\n";
typedef pair<int, int> pii;


int main() {
    int T;
    cin >> T;

    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph;
        vector<vector<int>> reverseGraph;
        graph.resize(n+1);
        reverseGraph.resize(n+1);
        vector<pii> allRoads;
        
        for (int i = 0; i < m; i++) {
            int source, dest;
            cin >> source >> dest;

            graph[source].push_back(dest);
            reverseGraph[dest].push_back(source);
            allRoads.push_back(pii(source, dest));
        }
        set<pii> roads;
        vector<int> visited(n+1, 0);
        
        stack<int> todo;
        todo.push(1);
        visited[1] = 1;

        while (!todo.empty()) {
            int curr = todo.top();
            todo.pop();
            
            for (int neighbour : graph[curr]) {
                if (visited[neighbour] != 1) {
                    todo.push(neighbour);
                    visited[neighbour] = 1;
                    roads.insert(pii(curr, neighbour));
                }
            }
        }

        visited.clear();
        visited.resize(n+1, 0);
        todo.push(1);
        visited[1] = 1;

        while (!todo.empty()) {
            int curr = todo.top();
            todo.pop();
            
            for (int neighbour : reverseGraph[curr]) {
                if (visited[neighbour] != 1) {
                    todo.push(neighbour);
                    visited[neighbour] = 1;
                    roads.insert(pii(neighbour, curr));
                }
            }
        }

        int count = m - 2*n;
        for (pii road : allRoads) {
            if (count == 0) {
                break;
            }
            if (roads.count(road) != 1) {
                cout << road.first << " " <<  road.second << nl;
                count--;
            }
        }
    }
    return 0;
}
