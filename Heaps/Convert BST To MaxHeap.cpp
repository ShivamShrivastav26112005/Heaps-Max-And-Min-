#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// BST class -> we make TreeNode class
class Node {
    public:
    int val;
    Node* left;
    Node* right;
    
    // constructor
    Node(int val) {
        this->val = val;
        left = right = NULL; // Initialize left and right children to NULL
    }
};

// inorder traversal -> left, root, right
// here we use reverse inorder traversal -> right, root, left
void inorder(Node* root, vector<int>& arr) {
    // & means we pass arr by reference, so we don’t create a new vector each time
    if (root == NULL) return;
    inorder(root->right, arr);
    arr.push_back(root->val);
    inorder(root->left, arr);
}

// display function to print array
void display(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// preorder traversal -> root, left, right
void preorder(Node* root, vector<int>& arr, int& i) {
    if (root == NULL) return;
    // update the root's value to fill the array's value (sorted in decreasing order)
    root->val = arr[i];
    i++; // or root->val = arr[i++];
    preorder(root->left, arr, i);
    preorder(root->right, arr, i);
}

// Levelorder traversal
void LevelorderQueue(Node* root) {
    if (root == NULL) return; // Edge case check
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->val << " ";
        
        if (temp->left != NULL) q.push(temp->left);
        if (temp->right != NULL) q.push(temp->right);
    }
    cout << endl;
}

int main() {
    // here we make BST -> 7 Nodes
    Node* a = new Node(10);
    Node* b = new Node(5);
    Node* c = new Node(16);
    Node* d = new Node(1);
    Node* e = new Node(8);
    Node* f = new Node(12);
    Node* g = new Node(20);
    
    // connection between parent and their children
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    
    // we make an empty array(arr) where we store ans in decreasing order by using (reverse inorder traversal)
    vector<int> arr;
    
    // reverse inorder traversal
    // store reverse inorder in the array.
    inorder(a, arr); // we pass two parameters: root node (a) and our empty array (arr) where we store our ans
    
    // Now we check our array is displayed in decreasing sorted order or not
    // display(arr);
    
    // before converting BST to MaxHeap, we print our BST by using Levelorder traversal.
    LevelorderQueue(a);
    
    // preorder traversal fills heap with decreasing order elements
    // we pass parameters -> root node, array, index (initially index starts from 0)
    int i = 0;
    preorder(a, arr, i); // BST is converted to MaxHeap
    
    // after preorder traversal, we display again to check if it is correct
    // display(arr);
    
    // at the end, we check if our BST is converted into MaxHeap by using Levelorder traversal
    LevelorderQueue(a);
    
    return 0;
}








#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int val;
    Node* left; 
    Node* right;
    Node(int val){
        this->val=val;
    }
};

void inorder(Node* root, vector<int>& arr){
    if(root==NULL) return ;
    inorder(root->right,arr);
    arr.push_back(root->val);
    inorder(root->left,arr);
}

void preorder(Node* root, vector<int>& arr, int& i){
    if(root==NULL) return ;
    root->val=arr[i++]; 
    preorder(root->left,arr,i);
    preorder(root->right,arr,i);
}


void LevelorderQueue(Node* root){
    queue<Node*>q;
    q.push(root); 
    while(q.size()>0){
        Node* temp=q.front(); 
        q.pop();
        cout<<temp->val<<" "; 
        if(temp->left!=NULL) q.push(temp->left); 
        if(temp->right!=NULL) q.push(temp->right);
    }
    cout<<endl;
}

int main(){
    Node* a = new Node(10);
    Node* b = new Node(5);
    Node* c = new Node(16);
    Node* d = new Node(1);
    Node* e = new Node(8);
    Node* f = new Node(12);
    Node* g = new Node(20);

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;

    vector<int> arr;
    inorder(a,arr);
    LevelorderQueue(a); 
    int i=0;
    preorder(a,arr,i); 
    LevelorderQueue(a);     
}




