#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define INF 0x3f3f3f3f
typedef long long ll;

struct Node {
    int id;
    int dist;
    bool operator < (const Node &other) const {
        return dist > other.dist;
    }
    Node(int id, int dist) {
        this->id = id;
        this->dist = dist;
    }
};

class Hall {
    public:
        int from;
        int to;
        int startTime;
        int endTime;
        int travelTime;
        Hall(int from, int to, int startTime, int endTime, int travelTime) {
            this->from = from;
            this->to = to;
            this->startTime = startTime;
            this->endTime = endTime;
            this->travelTime = travelTime;
        }
};

void dijkstra(vector<vector<Hall>> &rooms, vector<int> &dist, int n) {
    priority_queue<Node> pq;
    vector<int> visited(n+1, 0);
    visited[0] = 1;

    Node firstRoom(1, dist[1]);
    pq.push(firstRoom);
    
    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        if (visited[curr.id] != 1) {
            visited[curr.id] = 1;
            for (vector<Hall>::iterator it = rooms[curr.id].begin(); it != rooms[curr.id].end(); ++it) {
                if ((*it).endTime - curr.dist >= (*it).travelTime) {
                    if (curr.dist < (*it).startTime) {
                        dist[(*it).to] = min(dist[(*it).to], (*it).startTime+(*it).travelTime);
                    } else {
                        dist[(*it).to] = min(dist[(*it).to], curr.dist+(*it).travelTime);
                    }
                }
                Node temp((*it).to, dist[(*it).to]);
                pq.push(temp);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector< vector<Hall> > rooms;
    rooms.resize(n+1);
    //room 0 does not exist
    vector<Hall> filler;
    rooms[0] = filler;

    for (int i = 0; i < m; i++) {
        int from, to, startTime, endTime, travelTime;
        cin >> from >> to >> startTime >> endTime >> travelTime;
        
        if (travelTime <= endTime - startTime) {
            Hall first(from, to, startTime, endTime, travelTime);
            Hall second(to, from, startTime, endTime, travelTime);
            rooms[from].push_back(first);
            rooms[to].push_back(second);
        }
    }

    vector<int> dist(n+1, INF);
    dist[1] = 0;
    dijkstra(rooms, dist, n);
    /* 
    for(int i = 1; i <= n; i++) {
        cout << "Room " << i << ": " << dist[i] << nl;
    }
    */
    if (dist[n] != INF) {
        cout << dist[n] << nl;
    } else {
        cout << "danger" << nl;
    }
    return 0;
}
