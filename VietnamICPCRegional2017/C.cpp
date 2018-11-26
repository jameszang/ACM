#include <bits/stdc++.h>

using namespace std;

#define nl '\n'

class Node {
    public:
        int val;
        vector<Node*> neighbors;
        Node(int val) {
            this->val = val;
            neighbors.resize(0);
        }
};

int N;
vector<int> D;

bool addNode(int num, Node *n, set<int> &visited) {
    if (!visited.count(n->val) == 1) {
        visited.insert(n->val);
        if (n->neighbors.size() < D[n->val]) {
            Node *nd = new Node(num);
            n->neighbors.push_back(nd);
            nd->neighbors.push_back(n);
            //cout << "added " << nd->val << " to " << n->val << nl;
            return true;
        } else {
            bool retVal = false;
            for (vector<Node*>::iterator it = n->neighbors.begin(); it != n->neighbors.end(); ++it) {
                retVal = addNode(num, *it, visited);
                if (retVal) {
                    break;
                }
            }
            return retVal;
        }
    }
}

bool checkTree(Node *root, set<int> &visited) {
    if (!visited.count(root->val) == 1) {
        visited.insert(root->val);
        if (root->neighbors.size() != D[root->val]) {
            return false;
        } else {
            for (vector<Node*>::iterator it = root->neighbors.begin(); it != root->neighbors.end(); ++it) {
                if (!checkTree(*it, visited)) {
                    return false;
                }
            }
            return true;
        }
    } else {
        return true;
    }
}

int main() {
    cin >> N;
    D.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> D[i];
    }

    Node *root = new Node(1);
    
    for (int i = 2; i <= N; i++) {
        set<int> v;
        if( !addNode(i, root, v) ) {
            cout << "NO" << nl;
            return 0;
        }
    }
    set<int> v;
    if (checkTree(root, v)) {
        cout << "YES" << nl; 
    } else {
        cout << "NO" << nl;
    }
    return 0;
}
