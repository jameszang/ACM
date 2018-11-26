#include <iostream>

using namespace std;

#define nl '\n'

struct Interval {
    int low;
    int high;
};

class IntervalTree {
    private:
        class Node;
        void insert(Node *&subRoot, Interval i);
        void clear(Node *&subRoot);
        void printLows(Node *&subRoot);
        /* for debugging */
        void printIntervals(Node *&subRoot);
        
        Node *root;
        int numNodes;
    
    public:
        IntervalTree();
        ~IntervalTree();
        void insert(Interval i);
        void printLows();
        /* for debugging */
        void printIntervals();
        int numIntervals();
};

class IntervalTree::Node {
    public:
        Interval i;
        Node *left, *right;
        Node(Interval i) {
            this->i = i;
            left = NULL;
            right = NULL;
        }
};

void IntervalTree::insert(Node *&subRoot, Interval i) {
    if (subRoot == NULL) {
        subRoot = new Node(i);
        numNodes++;
        return;
    } 
    if (i.low <= subRoot->i.low && i.high >= subRoot->i.high) {
        return;
    }
    bool needNew = true;
    if (i.low > subRoot->i.low && i.low <= subRoot->i.high) {
        needNew = false;
        subRoot->i.low = i.low;
    } 
    if (i.high < subRoot->i.high && i.high >= subRoot->i.low) {
        needNew = false;
        subRoot->i.high = i.high;
    }
    if (needNew) {
        if (i.low < subRoot->i.low) {
            insert(subRoot->left, i);
        } else {
            insert(subRoot->right, i);
        }
    }
}

void IntervalTree::clear(Node *&subRoot) {
    if (subRoot->left != NULL) {
        clear(subRoot->left);
    }
    if (subRoot->right != NULL) {
        clear(subRoot->right);
    }
    delete subRoot;
}

void IntervalTree::printLows(Node *&subRoot) {
    if (subRoot == NULL) {
        return;
    } 
    printLows(subRoot->left);
    cout << subRoot->i.low << " ";
    printLows(subRoot->right);
}

/* for debugging */
void IntervalTree::printIntervals(Node *&subRoot) {
    if (subRoot == NULL) {
        return;
    }
    printIntervals(subRoot->left);
    cout << "[" << subRoot->i.low << ", " << subRoot->i.high << "]" << nl;
    printIntervals(subRoot->right);
}

IntervalTree::IntervalTree() {
    root = NULL;
    numNodes = 0;
}

IntervalTree::~IntervalTree() {
    clear(root);
}

void IntervalTree::insert(Interval i) {
    insert(root, i);
}

/* for debugging */
void IntervalTree::printIntervals() {
    printIntervals(root);
}

void IntervalTree::printLows() {
    printLows(root);
    cout << nl;
}

int IntervalTree::numIntervals() {
    return numNodes;
}

int main() {
    int n;
    cin >> n;

    IntervalTree iTree;

    for (int i = 0; i < n; i++) {
        Interval in;
        cin >> in.low >> in.high;
        iTree.insert(in);
    }

    //iTree.printIntervals();
    cout << iTree.numIntervals() << nl;
    iTree.printLows();

    return 0;
}
