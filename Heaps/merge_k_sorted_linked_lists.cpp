#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

Node* mergeKLists(Node* arr[], int N);

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}

   		Node *res = mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
// } Driver Code Ends


/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
  struct compare{
      
      bool operator()(Node* a, Node* b){
          return a->data > b->data;
      }
  };
  
Node * mergeKLists(Node *arr[], int N)
{
       // Your code here
       Node* dummy = new Node(0);
       Node* curr = dummy;
       
       priority_queue<Node*, vector<Node*>, compare> pq;
       
       for(int i=0; i<N; i++) pq.push(arr[i]);
       
       while(!pq.empty()){
           Node* temp = pq.top();
           pq.pop();
           
           curr->next = temp;
           curr = curr->next;
           if(temp->next) pq.push(temp->next);
       }
       return dummy->next;
}

