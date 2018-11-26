#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define nl '\n'
#define MOD_FACTOR 1000000007

class AVL {
    public:
        class Node {
            public:
                string s;
                Node *left;
                Node *right;

                Node(string s) {
                    this->s = s;
                    this->left = NULL;
                    this->right = NULL;
                }
        };

        Node *root;

        AVL() {
            root = NULL;
        }

        void insert(Node *subRoot, string s) {
            if (root == NULL) {
                root = new Node(s);
            } else {
                if (s < subRoot->s) {
                    insert(subRoot->left, s);
                } else {
                    insert(subRoot->right, s);
                }
            }
            rebalance(subRoot);
        }
        
        void updateHeight(Node *node) {
            node->height = 1 + max(height(node->left), height(node->right));
        }

        void rebalance(Node*& subtree) {
            if (abs(height(subtree->left) - height(subtree->right)) < 2) { // already balanced
                updateHeight(subtree);
            } else {
                if (height(subtree->left) > height(subtree->right)) { // L- imbalance
                    if (height(subtree->left->left) > height(subtree->left->right)) { // LL imbalance
                        rotateRight(subtree);
                    } else { // LR imbalance
                        rotateLeftRight(subtree);
                    }
                } else { // R- imbalance
                    if (height(subtree->right->left) > height(subtree->right->right)) { // RL imbalance
                        rotateRightLeft(subtree);
                    } else { // RR imbalance
                        rotateLeft(subtree);
                    }
                }
            }
        }
}

int main() {
    int n, k;
    cin >> n >> k;
    
    Node *head = new Node("");
    Node *curr = head;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        curr->next = new Node(s);
        curr = curr->next;
    }

    curr = head;
    for (int i = 0; i < n; i++) {
        curr = curr->next;
        cout << curr->s << nl;
    }

    string compareTo;
    cin >> compareTo;

    sort(strings.begin(), strings.end());

    int currPos = 0;
    long long ans = 0;
    vector<int> v;
    for (unsigned iteration = 0; iteration < k; iteration++) {
        for (unsigned i = 0; i < strings.size(); i++) {
            if (compareTo.compare(currPos, strings[i].length(), strings[i]) == 0) {
                v.push_back(i);
                currPos += strings[i].length();
                strings.erase(strings.begin() + i);
                break;
            }
        }
    }
    long long fact = 1;
    ans+=v[k-1];
    for(int i = n - k + 1; i < n; i++) {
        fact *= i;
        ans += fact * v[n-i-1];
    }
    ans++;
    ans %= MOD_FACTOR;
    cout << ans << nl;

    return 0;
}
