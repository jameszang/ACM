#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

struct Node {
        int dest;
        int prob;
        Node(int d, int p) : dest(d), prob(p) {}
        bool operator < (const Node& other) const {
            return (prob < other.prob);
        }
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<Node>> graph(N+1, vector<Node>());

    for (int i = 0; i < M; i++) {
        int a, b, p;
        cin >> a >> b >> p;

        graph[a].push_back(Node(b, p));
    }
    
    priority_queue<Node> pq;
    vector<bool> visited(N+1, false);
    vector<int> weights(N+1, 0);
    pq.push(Node(1, 1));
    visited[1] = true;
    weights[1] = 1;

    for (int i = 0; i < N; i++) {
        Node curr = pq.top();
        pq.pop();

        weights[curr.dest] = curr.prob;
        for (int j = 0; j < graph[curr.dest].size(); j++) {
            if (!visited[graph[curr.dest][j].dest]) {
                visited[graph[curr.dest][j].dest] = true;
                pq.push(Node(graph[curr.dest][j].dest, (curr.prob * graph[curr.dest][j].prob)));
            }
        }
    }

    cout << weights[N] << nl;

    return 0;
}
