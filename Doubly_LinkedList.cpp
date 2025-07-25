#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }

};
class Doubly_LinkedList{
    Node* head;
    Node* tail;
   public:
    Doubly_LinkedList(){
        head=tail=NULL;
    } 
    void Push_front(int val){
        Node* newnode = new Node(val);
         if(head==NULL){
            head=tail=newnode;
            return;
         }
         newnode->next=head;
         head->prev=newnode; 
         head=newnode; 
    }
    void Push_back(int val){
        Node* newnode = new Node(val); 
        if(head==NULL){
            head=tail=newnode;
            return;
         }
         tail->next = newnode;
         newnode->prev = tail;
         tail = newnode;
    } 
    void Pop_front(){
        if(head==NULL){
            cout<<"LinkedList is emptyt";
            return;
        }
        Node* temp=head;
        head=head->next;
        if(head!=NULL){
              head->prev =NULL; 
              return;
        }
        temp->next=NULL;
        delete temp;
    }  
    void Pop_back(){
        if(head==NULL){
            cout<<"LinkedList is emptyt";
            return;
        }
        Node* temp=tail;
        tail=tail->prev;
        if(tail!=NULL){
        tail->next=NULL; 
        return;
        } 
        temp->prev=NULL;
        delete tail;
    }
    void print(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"<=> ";
            temp=temp->next;
        }
        cout<<"NULL";
    }
};
int main(){
    Doubly_LinkedList dll;

    dll.Push_front(4);
    dll.Push_front(3);
    dll.Push_front(2);
    dll.Push_front(1);

    dll.Push_back(5);
    dll.Push_back(6);
    dll.Push_back(7);

    dll.Pop_front();
    dll.Pop_front();

    dll.Pop_back();
    dll.Pop_back();
    


    dll.print();

    return 0;


}