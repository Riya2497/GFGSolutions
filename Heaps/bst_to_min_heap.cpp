#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    
    struct Node* left;
    int data;
    struct Node* right;
    
};

Node* getNode(int val){
    
    Node* newnode = new Node;
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    
    return newnode;
}

Node* insert(Node* root, int val){
    
    if(root == NULL) return getNode(val);
    
    if(val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    
    return root;
    
}
void inorder(vector<int> &A, Node* root){
    
    if(root == NULL) return;
    inorder(A, root->left);
    A.push_back(root->data);
    inorder(A,root->right);
}
Node* minHeap(Node* root){
    
    if(root == NULL) return root;
    if(!root->left && !root->right) return root;
    
    vector<int> A;
    inorder(A, root);
    
    int i = 0;
    queue<Node*> q;
    Node* curr = root;
    
    q.push(curr);
    while(!q.empty()){
        
        int size = q.size();
        while(size--){
            q.front()->data = A[i];
            Node* temp = q.front();
            q.pop();
            i++;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            
        }
    }
    return root;
}
int main() {
	
	int n, val;
	Node* root = NULL;
	
	cin>>n;
	while(n--){
	    cin>>val;
	    root = insert(root, val);
	}
	
	root = minHeap(root);
	queue<Node*> q;
	Node* curr = root;
    
    q.push(curr);
    while(!q.empty()){
        
        int size = q.size();
        while(size--){
            Node* temp = q.front();
            cout<<temp->data<<" ";
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            
        }
        cout<<endl;
    }
	
	return 0;
}
