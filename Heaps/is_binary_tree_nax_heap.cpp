#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

bool isHeap(struct Node * tree);

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }

     cout << isHeap(root)<< endl;
  }
  return 0;
}

// } Driver Code Ends


/*
 A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

/*You are required to complete this method */
bool isHeap(Node * root)
{
 // Your code here
 if(root == NULL) return true;
 bool l, r, l1, r1;
 
 l = isHeap(root->left);
 r = isHeap(root->right);
 if(l && r){
     l1 = true;
     r1 = true;
     if(root->left) l1 = (root->data > root->left->data) ? true : false;
     if(root->right) r1 = (root->data > root->right->data) ? true : false;
     
     return (l1 && r1);
     
 }
 
 return false;
}
