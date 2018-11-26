#include <bits/stdc++.h>

#define nl '\n'
#define INF 0x3f3f3f3f
typedef long long ll;

using namespace std;

struct Node {
    int id;
    ll dist;
    int parent;
    Node(){}
    Node(int i, ll d, int p): id(i), dist(d), parent(p) {}
    bool operator < (const Node& other) const {
        return dist > other.dist;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> graph(n+1, vector<pair<int, int>>());

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        graph[a].push_back(make_pair(b, w));
        graph[b].push_back(make_pair(a, w));
    }

    vector<bool> visited(n+1, false);
    vector<int> distance(n+1, INF);
    vector<int> parent(n+1, -1);

    priority_queue<Node> pq;
    pq.push(Node(1, 0, -1));

    while (!pq.empty()) {
        Node temp = pq.top();
        pq.pop();
        if (!visited[temp.id]) {
            visited[temp.id] = true;
            distance[temp.id] = temp.dist;
            parent[temp.id] = temp.parent;
            for (int i = 0; i < graph[temp.id].size(); i++) {
                pq.push(Node(graph[temp.id][i].first, temp.dist + graph[temp.id][i].second, temp.id));
            }
        }
    }

    if (visited[n]) {
        vector<int> path;
        path.push_back(n);
        int idx = n;
        while (parent[idx] != -1) {
            path.push_back(parent[idx]);
            idx = parent[idx];
        }

        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << nl;
    } else {
        cout << -1 << nl;
    }
    
    return 0;
}
