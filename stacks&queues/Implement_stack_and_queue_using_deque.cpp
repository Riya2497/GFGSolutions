#include <iostream>
#include <climits>

using namespace std;

struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};
class Deque{
    
    private:
    Node* head;
    Node* tail;
    
    public:
    
    Deque(){
        head = NULL;
        tail = NULL;
    }
    
    bool isEmpty(){
        
        if(head == NULL) return true;
        
        else return false;
    }
    void insertFirst(int val){
        Node* newnode = new Node;
        newnode->data = val;
        newnode->next = NULL;
        newnode->prev = NULL;
        
        if(head == NULL){
            head = newnode;
            tail = newnode;
            return;
        }
        else{
            
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }
    
    void insertLast(int val){
        Node* newnode = new Node;
        newnode->data = val;
        newnode->next = NULL;
        newnode->prev = NULL;
        
        if(head == NULL){
            head = newnode;
            tail = newnode;
            return;
        }
        else{
            
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        
    }
    
    int removeFirst(){
        
        if(isEmpty()){
            cout<<"underflow!!"<<" ";
            return INT_MIN;
        }
        
        Node* temp = head;
        head = head->next;
        if(head){
            head->prev = NULL;
        }
        else{
            head = NULL;
            tail = NULL;
        }
        temp->next = NULL;
        int ans = temp->data;
        free(temp);
        return ans;
        
    }
    int removeLast(){
        if(isEmpty()){
            cout<<"underflow!!"<<" ";
            return INT_MIN;
        }
        
        Node* temp = tail;
        tail = tail->prev;
        if(tail) tail->next = NULL;
        else {
            head = NULL;
            tail = NULL;
        }
        
        temp->prev = NULL;
        int ans = temp->data;
        free(temp);
        return ans;
    }
    
    
};

class Stack : public Deque{
    
    public:
    
    void push(int val){
        insertLast(val);
    }
    
    int pop(){
        
        return removeLast();
    }
};

class Queue: public Deque{
    
    public :
    
    void enqueue(int val){
        insertLast(val);
    }
    
    int dequeue(){
        
        return removeFirst();
    }
};
int main()
{
   Stack stk ;
   
   stk.push(1);
   stk.push(2);
   
   cout<<stk.pop()<<endl;
   cout<<stk.pop()<<endl;
   cout<<stk.pop()<<endl;
   
   Queue q ;
   q.enqueue(1);
   q.enqueue(2);
   
   cout<<q.dequeue()<<endl;
   cout<<q.dequeue()<<endl;
   cout<<q.dequeue()<<endl;
   
   
   
   return 0;
}
