// // Ques-> Convert Binary Search tree(BST) to Maxheap.


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// BST class 
class Node{
public:
    int val;
    Node* left; 
    Node* right;
    // constructor
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

// inorder traversal -> left,root,right
// reverse inorder -> right,root,left
void inorder(Node* root, vector<int>& arr){ 
    if(root==NULL) return ;
    inorder(root->right,arr);
    arr.push_back(root->val);
    inorder(root->left,arr);
}

void display(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// preorder traversal -> root,left,right
void preorder(Node* root, vector<int>& arr, int& i){
    if(root==NULL) return ;
    root->val=arr[i]; i++; // root->val=arr[i++];
    preorder(root->left,arr,i);
    preorder(root->right,arr,i);
}

// Levelorder traversal
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
    // 7 Nodes 
    Node* a = new Node(10);
    Node* b = new Node(5);
    Node* c = new Node(16);
    Node* d = new Node(1);
    Node* e = new Node(8);
    Node* f = new Node(12);
    Node* g = new Node(20);
    // connection 
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;


    vector<int> arr;
   
    inorder(a,arr); 
    display(arr); 
    LevelorderQueue(a); 

    int i=0;
    preorder(a,arr,i); 
    display(arr);  
    LevelorderQueue(a);     

}

// IMP -: 
// 10 5 16 1 8 12 20 -> BST -> traversal level wise
// 20 16 8 12 10 5 1 -> maxheap -> traversal level wise (BST to maxheap -> property LST>RST)
// you can make both above given nodes and seen result. 


// Process -: 
// reverse inorder maxheap ke case me 
// minheap banana hai to inorder traversal karo array me 
// store karo preorder wise vapis se track kar do 










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
        this->left=NULL;
        this->right=NULL;
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

// 10 5 16 1 8 12 20 
// 20 16 8 12 10 5 1 









// Ques-> Convert Binary Search tree(BST) to Minheap.



#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// BST class
class Node{
public:
    int val;
    Node* left; 
    Node* right;
    // constructor
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

// inorder traversal -> left,root,right
void inorder(Node* root, vector<int>& arr){ 
    if(root==NULL) return ;
    inorder(root->left,arr);
    arr.push_back(root->val);
    inorder(root->right,arr);
}

void display(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


// preorder traversal -> root,left,right
void preorder(Node* root, vector<int>& arr, int& i){
    if(root==NULL) return ;
    root->val=arr[i]; i++; // or root->val=arr[i++];
    preorder(root->left,arr,i);
    preorder(root->right,arr,i);
}

// Levelorder traversal -> used to print BST 
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
    // 7 Nodes 
    Node* a = new Node(10);
    Node* b = new Node(5);
    Node* c = new Node(16);
    Node* d = new Node(1);
    Node* e = new Node(8);
    Node* f = new Node(12);
    Node* g = new Node(20);

    // connection
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
  
    vector<int> arr;

    inorder(a,arr); 

    display(arr); 

    LevelorderQueue(a); 

    
    int i=0;
    preorder(a,arr,i); 
    
    display(arr);  

    LevelorderQueue(a);     

}

// IMP -: 
// 10 5 16 1 8 12 20 -> BST -> traversal level wise
// 1 5 12 8 10 16 20  -> minheap -> traversal level wise (BST to minheap -> property LST<RST)
// you can make both above given nodes and seen result. 







// Inorder Traversal: This function traverses the BST in inorder (left, root, right),
// which gives us the elements in increasing order. We store these elements in a vector.

// Preorder Traversal: This function takes the sorted array and fills the 
// tree in a preorder manner (root, left, right). This ensures that the root node 
// gets the smallest element, followed by its left and right children, maintaining the MinHeap property.

// Level Order Traversal: This function is used to display the elements of the 
// tree level by level to verify the conversion.



