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
        } 
        newnode->next=head;
        head=newnode;
    }
    void Push_Back(int val) {
        Node* newnode= new Node(val);
        if(head ==  NULL) {
            head=tail=newnode;
            return;
        } 
        tail->next=newnode;
        tail = newnode;
                
    }
    void Pop_Front(){
        if(head == NULL){
            cout<<"Linked List Is Empty";
            return;
        }
        Node* curr = head;
        head = head->next;
       // curr-> next = NULL;
        delete curr;
    }
    void Pop_Back(){
        if(head == NULL){
            cout<<"Linked List Is Empty";
            return;
        }
        Node* curr = head;
        while(curr->next != tail){   // we are running this loop to fetch the previous value of tail
            curr=curr->next;
        }
        curr-> next = NULL;  // here previous node of tail is null which means this node has become tail
        delete tail;
        tail=curr;
    }
    void Insert(int pos, int val){
        if(pos<0)
        {
            cout<<"Inalid Position"<<endl;
            return;
        }
        if(pos==0){
            Push_Front(val);
            return;
        }
        Node* temp = head;
        for(int i=0; i<pos-1; i++){
            if(temp==NULL){
                cout<<"Invalid Position";
                return;
            }
            temp=temp->next;
        }
        Node* newnode = new Node(val);
        newnode->next = temp->next;
        temp->next=newnode;
    }
    int search(int key){
        Node* temp = head;
        int indx= 0;
        while(temp != NULL){
            if(temp->data==key){
                return indx;
            }
            temp=temp->next;
            indx++;
        }
        return -1;

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

    ll.Insert(3,10);
    ll.Insert(4,11);

    // ll.Pop_Front();
    // ll.Pop_Front();
    
    ll.Pop_Back();
    ll.Pop_Back();
    ll.Push_Back(99);

    ll.Printll();
    cout<<ll.search(4);

    return 0;
}
