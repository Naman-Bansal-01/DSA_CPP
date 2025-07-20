#include <iostream>
using namespace std;
class Node {
    public:
        int data;
        Node* next;
        Node(int val) {
            data = val;
            next = NULL;
        }
};

class LinkedList {
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = tail = NULL;
    }
    void Push_Front(int val) {
        Node* newnode= new Node(val);
        if(head ==  NULL) {
            head=tail=newnode;
            return;
        } else {
            newnode->next=head;
            head=newnode;
        }
    }
    void Push_Back(int val) {
        Node* newnode= new Node(val);
        if(head ==  NULL) {
            head=tail=newnode;
            return;
        } else {
            tail->next=newnode;
            tail = newnode;
                }
    }
    void Pop_Front(){
        if(head == NULL){
            cout<<"Linked List Is Empty";
        }
        Node* curr = head;
        head = head->next;
        curr-> next = NULL;
        delete curr;
    }
    void Pop_Back(){
        if(head == NULL){
            cout<<"Linked List Is Empty";
        }
        Node* curr = head;
        while(curr->next != tail){   // we are running this loop to fetch the previous value of tail
            curr=curr->next;
        }
        curr-> next = NULL;  // here previous node of tail is null which means this node has become tail
        delete tail;
        tail = curr;
    }
    void Printll() {
        Node* temp = head;
        while(temp != NULL) {
            cout<<temp->data<<"-> ";
            temp= temp->next;
        }
        cout<<"Null"<<endl;
    }

};
int main() {
    LinkedList ll;
    ll.Push_Front(1);
    ll.Push_Front(2);
    ll.Push_Front(3);
    ll.Push_Back(4);
    ll.Push_Back(5);
    ll.Push_Back(6);

    // ll.Pop_Front();
    // ll.Pop_Front();
    
    // ll.Pop_Back();
    // ll.Pop_Back();

    ll.Printll();

    return 0;
}
