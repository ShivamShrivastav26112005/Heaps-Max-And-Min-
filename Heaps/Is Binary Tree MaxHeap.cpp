#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    
    Node(int val) {
        this->val = val;
        this->left = NULL; // Initialize left child to NULL
        this->right = NULL; // Initialize right child to NULL
    }
};

int sizeoftree(Node* root) {
    if (root == NULL) return 0;
    return 1 + sizeoftree(root->left) + sizeoftree(root->right);
}

bool isCBT(Node* root) {
    if (root == NULL) return true; // Edge case: Empty tree is a CBT
    
    int size = sizeoftree(root);
    int count = 0;
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) { // Iterate until queue is empty
        Node* temp = q.front(); // temp = node
        q.pop();
        count++;
        
        if (temp != NULL) {
            q.push(temp->left); // Push left child
            q.push(temp->right); // Push right child
        } else {
            break; // If a NULL node is found, break the loop
        }
    }
    
    // Check if any non-NULL node is left in the queue
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp != NULL) return false; // If temp is non-NULL, then it's not a CBT
    }
    
    return true;
}

bool isMax(Node* root) {
    if (root == NULL) return true; // Edge case: Empty tree is max-heap
    
    if (root->left != NULL && root->val < root->left->val) return false;
    if (root->right != NULL && root->val < root->right->val) return false;
    
    return isMax(root->left) && isMax(root->right);
}

int main() {
    // we make our binary tree
    Node* a = new Node(20); // root
    Node* b = new Node(15);
    Node* c = new Node(10);
    Node* d = new Node(8);
    Node* e = new Node(11);
    Node* f = NULL; // Explicitly assigning NULL
    Node* g = new Node(6);
    
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f; // No need to assign NULL explicitly, as f is already NULL
    c->right = g;
    
    // solution
    if (isCBT(a) && isMax(a)) cout << "Tree is Maxheap";
    else cout << "Tree is not a Maxheap";
}


